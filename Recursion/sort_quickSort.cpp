#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){

    int pivot = arr[s];

    int count = 0;
    
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIdx= s + count;
    swap(arr[pivotIdx], arr[s]);

    int i = s, j = e;

    while(i< pivotIdx  && j > pivotIdx) {

        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIdx && j > pivotIdx) {
            swap(arr[i++] , arr[j--]);
        }
    }

    return pivotIdx;
}




void quicksort(int arr[], int s, int e) {

    //base case
    if(s >= e){
        return;
    }

    int p = partition(arr, s, e);

    //left part -> rec call
    quicksort(arr, s, p-1);

    //right part
    quicksort(arr, p+1, e);
}

int main()  {

    int arr[5] = {3,1,4,5,2};
    int n=5;

    quicksort(arr, 0, n-1);

    cout<<"Sorted Array : ";
    for(int  i=0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}