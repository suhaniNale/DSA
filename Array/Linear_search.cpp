#include <iostream>
using namespace std;

int linearsearch(int arr[], int size , int target){
    for(int i=0; i<size; i++){
        if (arr[i] == target) {   //Found
            return i;

        }
    }
    return -1 ;   // not found
}

int main() {
    int arr[] = {4, 3, 5, 8, 9, 0, 2};
    int size = 7;
    int target = 8;

    cout<< "Target found at index :"<<linearsearch(arr, size, target)<<endl; 
    return 0;
}