#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> s ;
    
    s.push(5);
    s.push(7);
    s.push(9);

    s.pop();
    //s.pop();
    //s.pop();

    cout<<s.top()<<endl;

    if(s.empty()){
        cout<<"stack is empty"<<endl;

    }
    else{
        cout<<"stack is  not empty"<<endl;
    }

    return 0;
}