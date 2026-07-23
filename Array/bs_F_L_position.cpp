#include <iostream>
using namespace std;

int firstOcc(int arr[], int n , int key){
    int st = 0;
    int e = n-1;
    int mid = st +(e - st)/2;
    int  ans = -1;

    while( st <= e){

        if(arr[mid] == key){
             ans = mid;
             e = mid -1;
        }
        else if( arr[mid] < key){
            st = mid + 1;
        }
        else{ 
            //key < mid
            e = mid -1;
        }

        mid = st +(e - st)/2;
    }
    return ans;
}


int lastOcc(int arr[], int n , int key){
    int st = 0;
    int e = n-1;
    int mid = st +(e - st)/2;
    int  ans = -1;

    while( st <= e){

        if(arr[mid] == key){
             ans = mid;
             st = mid + 1;
        }
        else if( arr[mid] < key){
            st = mid + 1;
        }
        else{ 
            //key < mid
            e = mid -1;
        }

        mid = st +(e - st)/2;
    }
    return ans;
}
int main() {
    int even[5] ={1,2,3,3,5};

    cout<<" First occurence of 3 is at index :"<<firstOcc(even,5,3)<<endl;
    cout<<" Last occurence of 3 is at index :"<<lastOcc(even,5,3)<<endl;

    return 0;
}