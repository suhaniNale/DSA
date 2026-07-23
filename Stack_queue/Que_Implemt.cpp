#include <iostream>
#include <queue>
using namespace std;

class Queue {
    int * arr;
    int qfront;
    int rear;
    int size;


public:
    Queue() {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;

    }

    //public func of queue

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        if (rear == size){
            cout<<"Q is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;

        }
    }
    int front (){
        if(qfront == rear){
            return  -1;
        }
        else{
            return arr[qfront];
        }
    }

    //destructor
    ~Queue() {
        delete[] arr;
    }
}; 

int main() {

    Queue q ;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<< "front:" <<q.front()<<endl;

    cout<< "Deleted:"<<q.dequeue()<<endl;

    cout<< "front:" <<q.front()<<endl;

    if(q.isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is Not Empty"<<endl;
    }

    return 0;
}