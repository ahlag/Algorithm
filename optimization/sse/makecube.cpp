#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <immintrin.h>
#include <sys/time.h>
#include <tbb/tbb.h>


using namespace std;

typedef float R;

double get_current_time() {
	struct timeval tval;
	gettimeofday(&tval, NULL);
	return (tval.tv_sec + 1e-6 * tval.tv_usec);
}

int main ( void ) {

//-----------------------------------------------------------------------------------------------------------------------
    //Constants
    int nhills = 0;
    R cutoff = 1.0E-04;
    
    //Mesh
    R x_min = 0.0, x_max = 0.0, x_mesh = 0.0;
    R y_min = 0.0, y_max = 0.0, y_mesh = 0.0;
    R z_min = 0.0, z_max = 0.0, z_mesh = 0.0;
    
    R X_MESH = 0.0, Y_MESH = 0.0, Z_MESH = 0.0;
    
    R xm_peak = 0.0, ym_peak = 0.0, zm_peak = 0.0;
    R vhills_peak = 0.0;
    
    //Periodic
    int  ipbc_x = 0, ipbc_y = 0, ipbc_z = 0;
    
    //Counters
    
    //Calculation
    R rx = 0.0, ry = 0.0, rz = 0.0;
    R rwx = 0.0, rwy = 0.0, rwz = 0.0;
    R rw2 = 0.0;
    
//-----------------------------------------------------------------------------------------------------------------------
    //File Reading of makecube.dat
    fstream dat;
    
    dat.open("makecube.dat", ios::in);
    if(!dat.is_open()) {
        cout << "Couldn't find makecube.dat." << endl;
        return EXIT_FAILURE;
    }

    cout << "Reading makecube.dat" << endl << endl;
    
    string str, dummy;
    
    getline(dat,str);
    stringstream ss1(str);
    ss1 >> x_min >> x_max >> x_mesh >> ipbc_x >> dummy;
    
    getline(dat,str);
    stringstream ss2(str);
    ss2 >> y_min >> y_max >> y_mesh >> ipbc_y >> dummy;
    
    getline(dat,str);
    stringstream ss3(str);
    ss3 >> z_min >> z_max >> z_mesh >> ipbc_z >> dummy;
    
    X_MESH = round ( ( x_max - x_min ) / x_mesh ) + 1;
    Y_MESH = round ( ( y_max - y_min ) / y_mesh ) + 1;
    Z_MESH = round ( ( z_max - z_min ) / z_mesh ) + 1;
    
    //NaN Check
    bool isnan_x = isnan ( X_MESH );
    bool isnan_y = isnan ( Y_MESH );
    bool isnan_z = isnan ( Z_MESH );
    
    if( isnan_x ) { cout << "NaN of x found."; exit(1); }
    if( isnan_y ) { cout << "NaN of y found."; exit(1); }
    if( isnan_z ) { cout << "NaN of z found."; exit(1); }
    
    //X_MESH OUTPUT
    cout << "INPUT x_min, x_max, x_mesh, ipbc_x" << endl;
    cout << " x_min (real)     : lower bound of x, " << x_min << "." << endl;
    cout << " x_max (real)     : upper bound of x, " << x_max << "." << endl;
    cout << " x_mesh (real)    : mesh interval of x, " << x_mesh << "." << endl;
    cout << " ipbc_x (integer) : 0 (free) or 1 (periodic), " << ipbc_x << "." << endl;
    cout << " No. of x_mesh    : the mesh number of x, " << X_MESH << "." << endl;
    cout << endl;
    
    //Y_MESH OUTPUT
    cout << "INPUT y_min, y_max, y_mesh, ipbc_y" << endl;
    cout << " y_min (real)     : lower bound of y, " << y_min << "." << endl;
    cout << " y_max (real)     : upper bound of y, " << y_max << "." << endl;
    cout << " y_mesh (real)    : mesh interval of y, " << y_mesh << "." << endl;
    cout << " ipbc_y (integer) : 0 (free) or 1 (periodic), " << ipbc_y << "." << endl;
    cout << " No. of y_mesh    : the mesh number of y, " << Y_MESH << "." << endl;
    cout << endl;
    
    //Z_MESH OUTPUT
    cout << "INPUT z_min, z_max, z_mesh, ipbc_z" << endl;
    cout << " z_min (real)     : lower bound of z, " << z_min << "." << endl;
    cout << " z_max (real)     : upper bound of z, " << z_max << "." << endl;
    cout << " z_mesh (real)    : mesh interval of z, " << z_mesh << "." << endl;
    cout << " ipbc_z (integer) : 0 (free) or 1 (periodic), " << ipbc_z << "." << endl;
    cout << " No. of z_mesh    : the mesh number of z, " << Z_MESH << "." << endl;
    cout << endl;
    
    int nx = (int)X_MESH, ny = (int)Y_MESH, nz = (int)Z_MESH;
    
//-----------------------------------------------------------------------------------------------------------------------
    //Counting hills of hills.ini
    fstream file;
    
    file.open("hills.ini", ios::in);
    if(!file.is_open()) {
        cout << "Couldn't find hills.ini." << endl;
        return EXIT_FAILURE;
    }
    
    cout << "Reading hills.ini." << endl << endl;
    
    while( !file.eof() ) {
        getline(file,str);
        nhills++;
        if( nhills == 0 ) { cout << "nhills = 0"; exit(2); }
    }
    
    nhills = nhills - 1; //Overcount of EOF
    
    if( nhills % 3 != 0 ) { cout << "x,y or z is missing. Error termination of makecube."; exit(3); }

    nhills /= 3;
    
    dat.close();
    
//-----------------------------------------------------------------------------------------------------------------------
    //Dynamic Memory Allocation
    
    int * istep = new int[nhills];
    R * height = (R *) _mm_malloc(nhills * sizeof(R), 32);
    R * width = (R *) _mm_malloc(4 * nhills * sizeof(R), 32);
    R * center = (R *) _mm_malloc(4 * nhills * sizeof(R), 32);

//-----------------------------------------------------------------------------------------------------------------------
    //File reading of hills.ini
    
    //Read file from beginning
    file.clear(); //Input of fstream eof -> good
    file.seekg (0, file.beg);
    
    for( int i = 0; i < nhills; i++ ) {
        for( int j = 0; j < 3; j ++ ) {
            getline(file,str);
            stringstream ss4(str);
            ss4 >> istep[i] >> height[i] >> width[4 * i + j] >> center[4 * i + j] >> dummy;
        }
    }
    
    file.close();
    
//-----------------------------------------------------------------------------------------------------------------------
    //Print header of makecube.cube
    fstream makecube;
    
    makecube.open("makecube.cube", ios::out);
    if(!makecube.is_open()) {
        cout << "Couldn't find makecube.cube." << endl;
        return EXIT_FAILURE;
    }
    
    cout << "Printing header info: makecube.cube." << endl << endl;
    
    makecube << setprecision(8) << fixed
             << "MAKECUBE CUBE FILE." << endl
             << "OUTER LOOP: X, MIDDLE LOOP: Y, INNER LOOP: Z" << endl
             << setw(3) << 0  << "  " << x_max-x_min << "  " << y_max-y_min << "  " << z_max-z_min << endl
             << setw(3) << nx << "  " << setw(12) << 1.0 << "  " << 0.0 << "  " << 0.0 << endl
             << setw(3) << ny << "  " << setw(12) << 0.0 << "  " << 1.0 << "  " << 0.0 << endl
             << setw(3) << nz << "  " << setw(12) << 0.0 << "  " << 0.0 << "  " << 1.0 << endl;

//-----------------------------------------------------------------------------------------------------------------------
    //Write Hills
    fstream center_file;
    
    center_file.open("center.out", ios::out);
    if(!center_file.is_open()) {
        cout << "Couldn't find center.out." << endl;
        return EXIT_FAILURE;
    }
    
    for( int i = 0; i < nhills; i++ ) {
        center_file << setw(2) << " " << i+1  << "  "
                    << setw(6) << center[4 * i + 0] << "  "
                    << setw(5) << center[4 * i + 1] << "  "
                    << setw(5) << center[4 * i + 2] << endl;
    }
    
    center_file.close();
    
//-----------------------------------------------------------------------------------------------------------------------
    //Calculate sum of hills
    //Debugging
    
    cout << "Entering main loop." << endl << endl;
    
    R rw2cut = - log( cutoff );
    
    //Mesh_interval
    X_MESH = ( x_max - x_min ) / ( nx - 1 );
    Y_MESH = ( y_max - y_min ) / ( ny - 1 );
    Z_MESH = ( z_max - z_min ) / ( nz - 1 );
    
    vhills_peak = 0.0;
    
    xm_peak = 0.0;
    ym_peak = 0.0;
    zm_peak = 0.0;

    int nl = 0;
    for (int l = 0; l < nhills; ++l) {
    	if (istep[l] > 0) {
    		height[nl] = height[l];
    		width[4 * nl + 0] = width[4 * l + 0];
    		width[4 * nl + 1] = width[4 * l + 1];
    		width[4 * nl + 2] = width[4 * l + 2];
    		width[4 * nl + 3] = 1;
    		center[4 * nl + 0] = center[4 * l + 0];
    		center[4 * nl + 1] = center[4 * l + 1];
    		center[4 * nl + 2] = center[4 * l + 2];
    		nl++;
    	}
    }
    nhills = nl;

    register __m256 c360 = _mm256_set1_ps(360.0);
    register __m256 mipb = _mm256_set_ps(0.0, ipbc_z * 360, ipbc_y * 360, ipbc_x * 360, 0.0, ipbc_z * 360, ipbc_y * 360, ipbc_x * 360);
    register __m128 c360_128 = _mm_set1_ps(360.0);
    register __m128 mipb_128 = _mm_set_ps(0.0, ipbc_z * 360, ipbc_y * 360, ipbc_x * 360);
    
    R * tmp_vhills = new R[ny * nz];
    
    for( int i = 0; i < nx; i++ ) {
    	double st = get_current_time();
        R xm = x_min + X_MESH * i;
        tbb::parallel_for(0, ny, [&](int j) {
            R * temp = (R *) _mm_malloc(8 * sizeof(R), 32);
            R ym = y_min + Y_MESH * j;
            for( int k = 0; k < nz ; k++ ) {
                R vhills = 0.0;
                //Mesh point
                
                R zm = z_min + Z_MESH * k;

                __m256 xyz = _mm256_set_ps(0, zm, ym, xm, 0, zm, ym, xm);

                int idx = 0;
                int l = 0;
                for( ; l + 1 < nhills; l += 2 ) {

                    //Distance between hills center and mesh point

                    __m256 cen = _mm256_load_ps(&center[idx]);	// read center[idx + 0 : idx + 7]
                    __m256 wid = _mm256_load_ps(&width[idx]);		// read width[idx + 0 : idx + 7]
                    __m256 rxyz = _mm256_sub_ps(cen, xyz);		// center - xyzm

                    __m256 tmp = _mm256_div_ps(rxyz, c360);
                    tmp = _mm256_round_ps(tmp, _MM_FROUND_TO_NEAREST_INT);
                    tmp = _mm256_mul_ps(tmp, mipb);
                    rxyz = _mm256_sub_ps(rxyz, tmp);
                    rxyz = _mm256_div_ps(rxyz, wid);
                    rxyz = _mm256_mul_ps(rxyz, rxyz);
                    _mm256_store_ps(temp, rxyz);

                    R rw2_1 = 0.5 * (temp[0] + temp[1] + temp[2]);
                    R rw2_2 = 0.5 * (temp[4] + temp[5] + temp[6]);
                    if (rw2_1 < rw2cut) {
                        vhills += height[l] * expf ( -rw2_1 );
                    }
                    if (rw2_2 < rw2cut) {
                        vhills += height[l + 1] * expf ( -rw2_2 );
                    }
                    idx += 8;
                }
                
                if (l < nhills) {
                    __m128 xyz_128 = _mm_set_ps(0.0, zm, ym, xm);
                    for (; l < nhills; l++) {
                        __m128 cen = _mm_load_ps(&center[idx]);        // read center[idx + 0 : idx + 3]
                        __m128 wid = _mm_load_ps(&width[idx]);        // read width[idx + 0 : idx + 3]
                        __m128 rxyz = _mm_sub_ps(cen, xyz_128);        // center - xyzm
                    
                        __m128 tmp = _mm_div_ps(rxyz, c360_128);
                        tmp = _mm_round_ps(tmp, _MM_FROUND_TO_NEAREST_INT);
                        tmp = _mm_mul_ps(tmp, mipb_128);
                        rxyz = _mm_sub_ps(rxyz, tmp);
                        rxyz = _mm_div_ps(rxyz, wid);
                        rxyz = _mm_mul_ps(rxyz, rxyz);
                        _mm_store_ps(temp, rxyz);
                    
                        rw2 = 0.5 * (temp[0] + temp[1] + temp[2]);
                        if (rw2 < rw2cut) {
                            vhills += height[l] * expf ( -rw2 );
                        }
                        //idx += 4;
                    }
                }
                
                //cout << xm << " " << ym << "  " << zm << endl;
                
                //Print hills value
                //makecube << vhills << endl;
                tmp_vhills[nz * j + k] = vhills;
                //cout << "MESH: " << setw(2) << i+1 << " " << j+1 << " " << nz << " " << vhills << " " << (get_current_time() - st) << endl;
                //Peak position
            }
            _mm_free(temp);
        });
        
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                R vhills = tmp_vhills[nz * j + k];
                if( vhills > vhills_peak ) {
                    vhills_peak = vhills;
                    xm_peak     = xm;
                    ym_peak     = y_min + Y_MESH * j;
                    zm_peak     = z_min + Z_MESH * k;
                }
                makecube << vhills << endl;
            }
        }
        
        cout << "MESH: " << setw(2) << i+1 << " " << ny << " " << nz << " " << vhills_peak << " " << (get_current_time() - st) << endl;
    }
    
    cout << endl;
    
    makecube.close();
    
//-----------------------------------------------------------------------------------------------------------------------
    //Print results
    
    cout << "Peak position: " << xm_peak << "  " << ym_peak << "  " << zm_peak << endl << endl
         << setprecision(8) << fixed
         << "Peak height (hartree): " << vhills_peak << endl << endl
         << "Peak height (kcal/mol): " << vhills_peak*627.51 << endl << endl
         << "Normal termination of makecube." << endl << endl;
    
//-----------------------------------------------------------------------------------------------------------------------
    
    delete[] istep;
    delete[] height;
    delete[] width;
    delete[] center;
    delete[] tmp_vhills;

    return 0;
}
