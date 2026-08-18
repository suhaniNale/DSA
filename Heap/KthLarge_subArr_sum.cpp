#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargestSubarraySum( vector<int> & arr, int k){

    //min heap
    priority_queue<int, vector<int>, greater<int> > mini;

    int n = arr.size();
    // Start from every index
    for(int i = 0; i<n; i++){
        int sum = 0;
        //generate all subarr starting at i
        for(int j = i; j<n; j++){

            sum += arr[j];

            //keep only k largest sums
            if(mini.size() < k){
                mini.push(sum);
            }

            else{
                if(sum > mini.top()){
                    mini.pop();
                    //push largest sum
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main (){

    vector<int>  arr = {1 , 2,6,4,3 };

    int k = 2;

    cout<<" Kth Largest SubArray Sum: "<<kthLargestSubarraySum(arr, k)<<endl;

    return 0;
}