#include <iostream>

using namespace std;

int main() {
    
    double x = 3.14, *fp;
    void *vp;
    
    vp = &x;
    fp = vp;
    
    cout << "ポインタ変数fpのアドレスは" << fp << "です" << endl;
    cout << "ポインタ変数vpのアドレスは" << vp << "です" << endl;
    
    cout << "ポインタ変数fpが指す内容は" << *fp << "です" << endl;
    
    /*間接参照する場合はキャストが必要 */
    cout << "ポインタ変数vpが指す内容は" << *(double *)vp << "です" << endl;
    
    
    return 0;
}
