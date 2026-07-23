#include <iostream>
using namespace std;

int binary_Search(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }

        if(key > arr[mid]){ //go to right part
            start = mid+1;
        }
        else{
            end= mid-1;
        }

        mid = start + (end - start)/2;

    }
    return -1;
}

int main() {
     int even[6] = {2,4,5,8,9,13};
     int odd[5] = {12, 14, 22,24, 27};

     int evnIdx = binary_Search(even, 6, 9);
     cout<<" Index of  9 is: "<< evnIdx <<endl;

     int oddIdx = binary_Search(odd, 5, 25);
     cout<<" Index of  25 is: "<< oddIdx <<endl;
    return 0;
}