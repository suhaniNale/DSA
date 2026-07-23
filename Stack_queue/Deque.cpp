#include <iostream>
#include <queue>
using namespace std;


// TC-> O(1)
class Deque {

    int * arr;
    int front;
    int rear;
    int size;

public:

    Deque(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if((front == 0 && rear == size -1) ||(front != 0 && rear ==(front - 1 + size) % size))
        {
            return true;
        }
        else
            return false;
    }

    bool pushFront(int x) {
        //check full or not
        if(isFull()){
            return false;    // cannot push elm
        }
        else if(isEmpty()) {
            front = rear = 0;
        }
        else if(front == 0 && rear != size -1 ){
            front = size -1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size -1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront(){
        if(isEmpty()){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        } 

        else if(front == size -1 ){
            front = 0;      //to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }

    int popRear(){
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        } 

        else if(rear == 0 ){
            rear= size -1;      //to maintain cyclic nature
        }
        else{
            rear--;
        }
        return ans;
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }
};

int main(){

    Deque dq(5);

    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushFront(30);

    cout<<"front:"<<dq.getFront()<<endl;
    cout << "Rear : " << dq.getRear() << endl;

    cout<<"Pop front:"<<dq.popFront()<<endl;
    cout<<"Pop front:"<<dq.popFront()<<endl;

    dq.pushRear(40);
    dq.pushRear(50);

    cout<<"front:"<<dq.getFront()<<endl;
    cout<<"Rear:"<<dq.getRear()<<endl;

    cout << "Pop Rear: " << dq.popRear() << endl;
    cout << "Pop Rear: " << dq.popRear() << endl;

    return 0;



}