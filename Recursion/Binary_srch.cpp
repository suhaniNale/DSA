#include <iostream>
using namespace std;

void print(int *arr , int s , int e){
    
    for(int i=s; i<=e;i++) {
        cout<< arr[i] <<" ";
    }  cout << endl;
}

bool binarySearch(int *arr , int s, int e , int k) {

    print(arr, s , e);

    //base case
    //elem not found
    if(s>e)
        return false;
    int mid = s + (e-s)/2;
    cout<<"Mid is-> "<<arr[mid]<<endl;

    //found
    if(arr[mid] == k){
        return true;
    }
    //right subarray
    if(arr[mid] < k){
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}

int main() {

    int arr[] ={2, 4, 6, 8, 11, 9};
    int size = 6;
    int key = 1;

    cout<<"present or not->"<<binarySearch(arr, 0 , size-1, key)<<endl;
    return 0;
}