#include <iostream>
#include <vector>

using namespace std;

void rotateArray(vector<int> &arr){

    int n = arr.size();
    int last = arr[n-1];

    //shift all elm left to right
    for(int i = n-1; i>0 ; i--){
        arr[i]= arr[i-1];
    }
    //put last last elm to 1st posi
    arr[0] = last;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    rotateArray(arr);

    cout<< "Rotated Array : ";
    for(int x : arr){
        cout<< x<< " ";
    }

    return 0;
}