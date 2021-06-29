#include <iostream>

using namespace std;

// if we have an unsorted array - O(N)
void search(int array[], int n, int a) {
    
    // O(N)
    for(int i=0;i<n;i++)
        if(array[i] == a)
            cout << "Item found at index: " << i << endl;
}

int main(int argc, const char * argv[]) {
    
    int array[] = {1, 12, 4, 8, -2, 0, 1, 9};
    int n = sizeof(array) / sizeof(array[0]);
    
    search(array, n, 1);
    
    return 0;
}
