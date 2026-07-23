#include <iostream>
using namespace std;

void print(int *arr , int n){
    cout<<"size of array is :"<< n <<endl;

    for(int i=0; i<n;i++) {
        cout<< arr[i] <<" ";
    }  cout << endl;
}

bool linearSearch(int *arr , int size , int k) {

    print(arr, size);
    //base case
    if(size == 0 ){
        return false;
    }
    if(arr[0] == k ){
        return true;
    }
    else{
        bool remainingPart = linearSearch(arr+1, size-1, k);
        return remainingPart;
    }
    
}

int main() {

    int arr[] ={2, 4, 6, 8, 11, 9};
    int size = 6;
    int key = 8;

    bool ans = linearSearch(arr, size, key);

    if(ans){
        cout<<" present"<<endl;
    }
    else{
        cout<<" Not present"<<endl;
    }

    return 0;
}