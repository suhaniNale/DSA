#include <iostream>
#include <vector>
using namespace std;

//Kadane’s Algorithm
int maxSubArray(vector<int> & nums){
    int currSum = 0, maxSum= INT16_MIN;

    int start =0, end=0, tempStart=0;

    for (int i= 0; i< nums.size(); i++)
 {
    currSum += nums[i];
    //maxSum = max(currSum, maxSum );

    if(currSum > maxSum){
        maxSum = currSum;
        start = tempStart;
        end=i;
    }

    if(currSum < 0){
        currSum = 0;   // if sum -> -ve->reset to zero
        tempStart = i+1;
    }
 }
 cout<< "subarray:";
 for(int i = start; i <= end; i++){
    cout << nums[i] << " ";
 }
 cout<<endl;

 return maxSum;
}


int main() {
    int n;
    cout<<"enter num of elements:";
    cin>>n;

    vector<int> nums(n);

    cout<<"enter elements: ";
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    int result = maxSubArray(nums);
    cout<<" Maximum subArray Sum:"<<result<<endl;


    // int n= 5;
    // int arr[5] ={1,2,3,4,5};

    // for(int st=0; st<n; st++){
    //     for(int end=st; end<n;end++){
    //         for(int i= st; i<=end; i++){
    //             cout<<arr[i];
    //         }
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    //max_subarray_sum->
    


    
    return 0;
}