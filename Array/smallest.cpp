#include <iostream>
using namespace std;

int main() {
    int nums[] = {9, 10, 6, -14, 90, -15};
    int size= 6;

    // int smallest = INT8_MAX;
    // int largest = INT8_MIN;

    // for(int i = 0; i<size; i++){
    //     //min/max
    //     smallest = min(nums[i], smallest);
    //     largest = max(nums[i], largest);
    //     // if(nums[i] < smallest){
    //     //     smallest = nums[i];
    //     // }
    // }

    // cout <<"Smallest Number:"<<smallest<<endl;
    // cout <<"largest Number:"<<largest<<endl;

    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 0; i< size; i++){
        if(nums[i] < nums[minIdx]) {
            minIdx = i;
        }
        if(nums[i] > nums[maxIdx]){
            maxIdx = i;
        }
    }
    cout <<"index of Smallest Number:"<<minIdx<<endl;
    cout <<"index of largest  Number:"<<maxIdx<<endl;

    return 0;
}