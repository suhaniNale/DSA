#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(){

    vector <int> v ;

    // vector <int> a(5,1);
    // cout<<"print a"<<endl;
    // for(int i : a){
    //     cout<<i<<" ";
    // }

    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(8);

    cout<<"finding 6 ->"<<binary_search(v.begin(), v.end(), 6)<<endl;
    
    cout<<"Lower bound ->"<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<"Upper Bound ->" <<upper_bound(v.begin(), v.end(), 4) - v.begin()<<endl;

    int a = 3;
    int b = 5;

    cout<<"max ->"<<max(a,b)<<endl;
    cout<<"min ->"<<min(a,b)<<endl;

    swap(a,b);
    cout<< "a= "<<a<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"String->"<<abcd <<endl;


    rotate(v.begin(),v.begin()+1, v.end());
    cout<<"after rotate: "<<endl;
    for(int i: v){
        cout<<i<<" ";
    }

    
}