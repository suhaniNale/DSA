#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> v ;

    vector <int> a(5,1);
    cout<<"print a"<<endl;
    for(int i : a){
        cout<<i<<" ";
    }

    

    cout<<"\nCapacity -> "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(4);
    cout<<"Capacity -> "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"Capacity -> "<<v.capacity()<<endl;

    cout<<"Front: "<<v.front()<<endl;
    cout<<"Back: "<<v.back()<<endl;

}