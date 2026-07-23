#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    //copy of list -> n(l)
    list<int> n(5, 100);
    for(int i : n){
        cout<<i<<" ";
    }

    l.push_back(1);
    l.push_back(2);
    l.push_front(3);

    for(int i : l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"List Size: "<<l.size()<<endl;

    cout<<endl;
    l.erase(l.begin());
    cout<<"After earse: ";
    for(int i : l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"List Size: "<<l.size()<<endl;
    
}