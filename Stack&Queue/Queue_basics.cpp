#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(2);
    q.push(4);

    cout<<"front of Q is:"<<q.front()<<endl;
    q.push(7);
    q.push(10);
    cout<<"front of Q is:"<<q.front()<<endl;
    
    cout<<"size of the queue :"<<q.size()<<endl;

    q.pop();
    // q.pop();
    // q.pop();
    // q.pop();


    cout<<"size of the queue :"<<q.size()<<endl;

    if(q.empty()) {
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<<"queue is not empty "<<endl;
    }


    return 0;

}