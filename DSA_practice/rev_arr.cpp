#include <iostream>
#include <vector>
#include<algorithm> 

using namespace std;
/*
//naive appr-->  TC=O(n)  && SC=O(n)
void reverseArray1(vector<int> &arr){

    int n = arr.size();

    //1.create temp same size arr  
    vector<int> temp(n);

    //2.copy all elem from orignal arr in rev order
    for(int i =0; i<n; i++){
        temp[i] = arr[n-i-1];
    } 

    //3.copy elem back to original arr
    for(int i =0; i<n; i++){
         arr[i] = temp[i] ;
    }
}
*/

//optimal two ptr approach-> TC=O(n)  && SC=O(1)
void reverseArray(vector<int> &arr){

    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        //swap 1st and last elm
        swap(arr[left], arr[right]);

        //left ptr increment by 1
        left++;
        //right decrement by one
        right--;
    }
}

int main(){

    vector<int> arr = {1, 4, 3, 2, 6, 5};
    
    reverseArray1(arr);

    for(int i = 0;i < arr.size(); i++){
        cout<< arr[i]<< " ";
    }

    return 0;
}