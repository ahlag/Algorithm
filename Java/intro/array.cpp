#include <iostream>

using namespace std;

void incArray(int array[]) {
    for(int i = 0; i < 3 ; i++ ) {
        array[i]++;
    }
}

void print(int array[]) {
    for(int i = 0; i < 3; i++ ) {
        cout << array[i] << endl;
    }
}

int main() {
    int array[] = {1,2,3};
    incArray(array);
    print(array);
    return 0;
}
