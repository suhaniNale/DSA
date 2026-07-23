#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> q ;

    q.push("hi");
    q.push("hello");
    q.push("hey");



    cout<<"Size: "<< q.size()<<endl;
    cout<<"front elm:"<<q.front()<<endl;

    q.pop();
    cout<<"Size: "<< q.size()<<endl;
    cout<<"first elm:"<<q.front()<<endl;

    cout<<"Empty Or Not:"<<q.empty()<<endl;
}