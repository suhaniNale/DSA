#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n){

    for(int i =0 ; i < n-1; i++){  
        //for round 1 to n-1
        bool swapped = false;

        for(int j = 0; j < n-i-1 ; j++){

            if(arr[j]  > arr[j+1]){
                swap(arr[j]  , arr[j+1]);
                swapped = true;
            }
        }
        
        if(swapped ==false)
            break;
    }
}

int main() {
    vector<int> arr = {64, 85, 10, 22, 11};
    int n = arr.size();

    bubbleSort(arr, n);


    cout<<"sorted array: ";
    for(int x : arr){
        cout<< x <<" ";
    }
    
    
    return 0;
}