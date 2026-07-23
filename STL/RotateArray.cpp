#include <iostream>
#include <vector>
using namespace std;

void rotateArray(vector<int> &nums , int k) {
    int n= nums.size();
    vector<int> temp(n);

    for(int i=0;i<n;i++){
        temp[(i+k) % n] = nums[i];
    }

    nums= temp;
 }

void print(vector<int> v){
    for (int i : v){
        cout<< i<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int>  arr = {11,12,13,14};

    print(arr);

    cout<<"Rotated Array -> ";
    rotateArray(arr, 2);
    print(arr);
    return 0;
 }