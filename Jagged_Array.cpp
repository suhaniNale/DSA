#include <iostream>
using namespace std;

int main() {
    int rows = 3;

    // sizes of each row
    int sizes[] = {3, 2, 5};

    // allocate array of row pointers
    int** arr = new int*[rows];

    // allocate each row with different sizes
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[sizes[i]];
    }

    // assign values
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arr[i][j] = value++;
        }
    }

    // print jagged array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // deallocate memory (VERY IMPORTANT)
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}