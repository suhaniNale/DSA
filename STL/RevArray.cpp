#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v) {
    
    int s =0; 
    int e = v.size()-1;

    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
    
}

void print(vector <int> v ) {
    for( int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector <int> v ;


    v.push_back(11);
    v.push_back(2);
    v.push_back(7);
    v.push_back(4);
    v.push_back(8);

    vector<int> ans = reverse(v);

    cout<<"Printing Reverse Array -> "<<endl;
    print(ans);
    

    return 0;

}