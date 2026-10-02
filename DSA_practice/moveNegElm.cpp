#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
// //appr 1-> brute force-sorting arr   TC = O(n logn)  Sc= O(1)
// vector<int> moveNegative(vector<int> & arr){

//     sort(arr.begin(), arr.end());
//     return arr;
// }


//appr 2-> two pointer-> l & r       TC = O(n)  Sc= O(1)
vector<int> moveNegative(vector<int> & arr){

    int left = 0; 
    int right = arr.size() - 1;

    while(left < right){

        // increment left while arr[left] is negative
        while(left<right && arr[left]<0)
            left++;

        // decrement right while arr[right] is positive
        while(right>left && arr[right]>0){
            right--;
        }
        //swap 2 val
        if(right > left){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return arr;
}


int main(){

    vector<int>  arr =  {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    vector<int> ans = moveNegative(arr);

    cout<< "Array: " ;
    for(int num : ans){
        cout<< num<<" ";
    }

    return 0;
}