#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> pq ;

    pq.push(45);
    pq.push(67);
    pq.push(50);

    cout<<"top elm : "<<pq.top()<<endl;

    cout<<" size of pq : "<<pq.size()<<endl;

    pq.pop();

    cout<<"top elm : "<<pq.top()<<endl;

    cout<<" size of pq : "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"pq is  empty";
    }
    else{
        cout<<"pq is not empty";
    }


    return 0;

}