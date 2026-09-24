#include <iostream>
#include <vector>
#include<algorithm>
#include <climits> 

using namespace std;
//optimal solu-> iterating the array-> TC=O(n) and SC = O(1)
vector<int> findMinMax(vector<int> &arr){

    int n = arr.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    //find minimum and maximum
    for(int i = 0; i<n; i++){
        if(arr[i] < mini)  mini = arr[i];

        if(arr[i] > maxi )  maxi = arr[i];
    }
    return {mini, maxi};
}

int main(){

    vector<int> arr = {1, 4, 3, 2, 6, 5};
    
    vector<int> result = findMinMax(arr);

    cout<<result[0] <<" " << result[1]<< endl;

    return 0;
}