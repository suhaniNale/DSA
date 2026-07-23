#include <iostream>
#include <queue>
using namespace std;


//TC & SC = O(n)
void reverseQueue(queue <int> &q) {

    //base case
    if(q.empty()){
        return;
    }
    //remove 1st element
    int element = q.front();
    q.pop();

    //rec call
    reverseQueue(q);

    q.push(element);     // Insert removed element at rear

}

int main(){

    queue <int> q;

    q.push(4);
    q.push(3);
    q.push(8);
    q.push(10);

    reverseQueue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}