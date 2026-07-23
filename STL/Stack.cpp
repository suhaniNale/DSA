#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<string> s ;

    s.push("hi");
    s.push("hello");
    s.push("hey");

    

    cout<<"Size: "<< s.size()<<endl;
    cout<<"Top elm:"<<s.top()<<endl;

    s.pop();
    cout<<"Size: "<< s.size()<<endl;
    cout<<"Top elm:"<<s.top()<<endl;

    cout<<"Empty Or Not:"<<s.empty()<<endl;
}