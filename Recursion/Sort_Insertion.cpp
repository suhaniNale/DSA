#include <iostream>
using namespace std;

void sortArray(int arr[], int n ){

    //base case 
    if(n <= 1){
        return;
    }
    //1st sort n-1 elem
    sortArray(arr, n-1);

    //put last elem to its correct position
    int last = arr[n-1];
    int j = n-2;

    while(j >= 0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;           //stops when j => -1
    }

    arr[j+1] = last;

}


int main() {

    int arr[] = {12,10,6,18,3};
    int n =  sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;
    
    return 0;
}