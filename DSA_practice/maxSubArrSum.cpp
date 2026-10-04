#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySUM(vector<int> &arr){

    int maxSum = arr[0];
    int currSum = arr[0];

    //
    for(int i = 1; i<arr.size() ; i++){
        
        currSum = max(arr[i], currSum + arr[i]);

        //update maxSum
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main(){
    vector<int> arr =  {-2, 1, -3, 4, -1, 2, 1, -5, 4};


    cout<< "Maximum  Sub-Array Sum : "<< maxSubArraySUM(arr) <<endl;
    
    return 0;
}