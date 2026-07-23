#include <iostream>
using namespace std;

void sortArray(int *arr, int n){

    //base case -> already sorted array
    if(n==0  || n==1){
        return;
    }


    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }
    //recursive call
    sortArray(arr, n-1);
}


int main() {

    int arr[] = {2,10,6,18,9};
    int n = 5;

    sortArray(arr, 5);
    for(int i=0; i<5;i++){
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;
    
    return 0;
}