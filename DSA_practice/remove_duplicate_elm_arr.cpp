#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> remDuplicate(vector<int> & arr){

    // two ptr approach->i &  j
    //i->searches each elm     j->store unique elm posi
        
    //sort arr if it is not
    sort(arr.begin(), arr.end());

    int n= arr.size();
    int j = 1;

    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            arr[j] = arr[i];
            j++;
        }
    }
    arr.resize(j);
    return arr;
}

int main() {

    vector<int> arr = {2, 2, 3, 3, 7, 5};
    

    vector<int> res = remDuplicate(arr);

    cout<<"Final Array with unique Element: " ;

    for(int x : res){
        cout<< x << " ";
    }
    
    return 0;
}