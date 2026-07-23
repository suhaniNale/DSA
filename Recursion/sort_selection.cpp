#include <iostream>
using namespace std;

void sortArray(int *arr, int n ,int index){

    //base case 
    if(index >= n-1){
        return;
    }
    //for minimum elem
    int minIdx  = index;

    for(int i= index + 1 ; i<n; i++){
        if(arr[i] < arr[minIdx]){
            minIdx = i;
        }
    }

    //swap curr elem with min elem
    swap(arr[index] , arr[minIdx]);

    //recursive call
    sortArray(arr, n , index + 1);
}


int main() {

    int arr[] = {12,10,6,18,9};
    int n =  sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n, 0);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;
    
    return 0;
}