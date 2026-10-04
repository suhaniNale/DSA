#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int>  findIntersection(vector<int> &a , vector<int> & b){

    unordered_set <int> s(a.begin(), a.end());

    unordered_set <int> resultSet;

    for(int i = 0; i< b.size(); i++){

        if(s.find(b[i]) != s.end()){
            resultSet.insert(b[i]);
        }
        
    }

    vector<int> result  (resultSet.begin(), resultSet.end()) ;
    
    return result;
}


int main(){

    vector<int>  a =  {1, 2, 3, 2, 1};
    vector<int>  b =  {3, 2, 2, 3, 3, 2};

    vector<int> ans = findIntersection(a,b);

    cout<< "Intersection of Two Array: " ;
    for(int x : ans){
        cout<< x <<" ";
    }

    return 0;
}