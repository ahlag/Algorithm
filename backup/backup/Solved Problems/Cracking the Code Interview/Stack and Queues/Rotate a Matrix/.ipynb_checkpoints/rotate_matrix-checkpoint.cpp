/*
 * Cracking the coding interview edition 6
 * Problem 1.7 Rotate a matrix by 90' clockwise ( or anticlockwise).
 * Solution : I have done it two ways.
 * Approach 1: Take transpose of matrix and then reverse the rows for clockwise 90' rotation.
 * 			   Obviously if we reverse the columns we will get anticlockwise 90' rotation.
 * Approach 2: As mentioned in the book, rotating invididual elements layer by layer.
 * 			   I have solved it perform anticlockwise 90' rotation, it can be done similarly for clockwise rotatation.
 */
#include<iostream>

using namespace std;

void transpose(int ** matrix, int N) {

    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            if( i != j ) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

}

void reverse(int *row, int N) {

    for(int j = 0; j < N/2; j++) {
        swap(row[j], row[N-1-j]);
    }
}

void rotate1(int **matrix, int N) {

    // Transpose Matrix
    transpose(matrix, N);

    for(int i = 0; i < N; i++) {
        reverse(matrix[i], N);
    }

}

void anticlockwise_rotate(int **matrix, int N) {

	for( int i = 0; i < N/2; ++i ) {
		for( int j = i; j < N-i-1; ++j ) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][N-i-1];
				matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
				matrix[N-i-1][N-j-1]= matrix[N-j-1][i];
				matrix[N-j-1][i] = temp;
		}
	}

}

void rotate2(int **matrix, int N) {

	for( int i = 0; i < N/2; ++i ) {
		for( int j = i; j < N-i-1; ++j ) {
				int temp = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - j - 1];
                matrix[N - 1 - i][N - j - 1] = matrix[j][N - 1 -i];
                matrix[j][N - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
		}
	}

}

void printMatrix( int ** matrix, int N) {
	for ( int i = 0; i < N; ++i ) {
		for( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

    int N;
    cout << "Enter N for NxN matrix:";
    cin >> N;

	int ** matrix = new int*[N];
	for ( int i = 0; i < N; ++i ) {
		matrix[i] = new int[N];
	}

    for ( int i = 0; i < N; ++i) {
		for ( int j = 0; j < N; ++j ) {
			cin >> matrix[i][j];
		}
	}

    cout << "Rotated matrix by 90 (clockwise):\n";
	rotate1(matrix, N);
	printMatrix(matrix, N);

	cout << "Rotated matrix again by 90(anticlockwise):\n";
	anticlockwise_rotate(matrix, N);
	printMatrix(matrix, N);

    cout << "Rotated matrix by 90 (clockwise):\n";
	rotate2(matrix, N);
	printMatrix(matrix, N);

    return 0;
}