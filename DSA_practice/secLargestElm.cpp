#include <iostream>
#include <vector>
#include<algorithm>
#include <climits> 

using namespace std;
//TC= O(n)  and SC= O(1)
int secondLargest(vector<int> &arr){

    int largest = INT_MIN;
    int second  = INT_MIN;

    for(int num : arr){
    
        //found a new largest elm
        if(num > largest) {
            second = largest;
            largest = num;
        }
        //num is between large and second
        else if(num > second  && num != largest){
            second = num;
        }
    }
    //fewer than two distinct elm
    if(second == INT_MIN){
        return -1;
    }

    return second;

}

int main(){

    vector<int> arr = {12, 35, 1, 10, 34, 1};

    cout<< secondLargest(arr);

    return 0;
}