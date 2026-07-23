//cpp
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);   //new node create
    tail-> next = temp;
    tail = tail->next;
}

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<<temp -> data <<" ";
        temp = temp ->next;
    }
    cout<<endl;

    
}

int main() {

    Node* node1 = new Node(10);

    Node* head = node1; //point head
    Node* tail = node1;
    print(head);

    InsertAtTail(tail, 20);
    print(head);

    InsertAtTail(tail, 30);
    print(head);

    InsertAtTail(tail, 40);
    print(head);
    
    return 0;
}