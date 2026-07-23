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

Node * sortLinkedList (Node* head){
    //TC => O(n)

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0)
            zeroCount++;
        else if(temp -> data == 1)
            oneCount++;
        else if(temp -> data == 2)
            twoCount++;

        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount-- ; 
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;

        }
        else if (twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp ->next;

    }
    return head;

}
int main() {

    Node* node1 = new Node(1);

    Node* head = node1; //point head
    Node* tail = node1;
    //print(head);

    InsertAtTail(tail, 0);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);

    cout<<"before sorting: ";
    print(head);

    head = sortLinkedList(head);

    cout<<"After sorting: ";
    print(head);
    
    return 0;
}