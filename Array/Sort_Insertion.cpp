#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n){

    for(int i =1 ; i < n; i++){  
        int temp = arr[i];     //temp is value of idx i
        int j = i-1;
        //Move backwards through the sorted part
        for(; j >= 0 ; j--){

            if(arr[j]  > temp){
                //shift
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
        
        
    }
}

int main() {
    vector<int> arr = {64, 85, 10, 22, 11};
    int n = arr.size();

    insertionSort(arr, n);


    cout<<"sorted array: ";
    for(int x : arr){
        cout<< x <<" ";
    }
    
    
    return 0;
}