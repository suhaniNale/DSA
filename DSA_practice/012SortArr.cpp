#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
/*
//brute force-> sort algo-> TC = O(n logn)
void sortArray(vector<int> &arr){
    sort(arr.begin(), arr.end());
}
*/

//optimized appr->   store count of 0,1,2    TC = O(n)
void sortArray(vector<int> &arr){
    int n = arr.size();

    int count0 =0;
    int count1 =0;
    int count2 = 0;
    //O(n)
    for(int i = 0; i < n; i++){

        if(arr[i] == 0)   count0++;

        else if (arr[i]==1) count1++;

        else  count2++;
    }

    int index = 0;
    for(int i = 0; i<count0; i++){
        arr[index++] = 0 ;
    }

    for(int i=0; i<count1; i++){
        arr[index++] = 1;
    }

    for(int i=0; i<count2; i++){
        arr[index++] = 2;
    }

}

//3.optimal appr-> 
    


int main(){

    vector<int> arr = {0,2,1,2,0,1,2};

    sortArray(arr);

    cout<<"sorted array: ";

    for(int x : arr){
        cout<< x << " ";

    }

    return 0;
}