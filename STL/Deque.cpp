#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque<int> d;

    d.push_back(1);  //2 1
    d.push_front(2);
    d.push_front(3);

    //print
    for (int i : d){
        cout<<i<<" ";
    }
    
    // d.pop_back();
    // cout<<endl;
    // for (int i : d){
    //     cout<<i<<" ";
    // }

    cout<<endl;

    cout<<"print first index element: "<<d.at(1)<<endl;
    
    cout<<"Empty or Not: "<<d.empty()<<endl;

    cout<<"Before Erase: "<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+1);
    cout<<"After Erase: "<<d.size()<<endl;
    cout<<endl;
    for (int i : d){
        cout<<i<<" ";
    }
}