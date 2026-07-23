#include <iostream>
#include <queue>
using namespace std;


// TC-> O(1)
class CircularQueue {

    int * arr;
    int front;
    int rear;
    int size;

public:

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int data){
        if((front == 0  && rear == size -1) || (rear == (front - 1 + size) % size))
        {
            cout<< "Queue is full ";
            return false;
        }
        else if(front == -1){  //push 1st elem in empty queue
            front = rear = 0;
        }
        else if(rear == size -1 && front !=0){
            rear=0;
        }
        else{
            rear++;
            // arr[rear] = data;    
        }
        arr[rear] = data;
        return true;
    }

    int dequeue(){
        if(front == -1){  // check q empty?
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear)  //single elm present in q
        {
            front = rear = -1;
        }
        else if(front == size -1){
            front = 0  ;   // to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }
    //destructor
    ~CircularQueue() {
        delete[] arr;
    }
};


int main(){

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout<< q.dequeue()<<endl;
    cout<< q.dequeue()<<endl;

    q.enqueue(50);
    q.enqueue(60);    

    return 0;
}