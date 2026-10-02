#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int>  findUnion(vector<int> &a , vector<int> & b){

    unordered_set <int> s(a.begin(), a.end());

    for(int i = 0; i< b.size(); i++){
        s.insert(b[i]);
    }

    vector<int> result = vector<int> (s.begin(), s.end()) ;
    
    return result;
}


int main(){

    vector<int>  a =  {1, 2, 3, 2, 1};
    vector<int>  b =  {3, 2, 2, 3, 3, 2};

    vector<int> ans = findUnion(a,b);

    cout<< "Union of Two Array: " ;
    for(int x : ans){
        cout<< x <<" ";
    }

    return 0;
}