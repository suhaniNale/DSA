#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int d) {
    //new node create-temp
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
    
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next ;    // move to next node
    }
    cout<<endl;

}

void InsertAtposition(Node* &head, int position ,int d){

    if(position == 1){
        InsertAtHead(head, d );
        return;
    }
    Node* temp = head;

    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->  next = temp -> next;
    temp -> next = nodeToInsert;
}





int main() {
    //created a node
    Node* node1 = new Node(10);
    //cout<< node1 -> data<<endl;
    //cout<< node1 -> next<<endl;

    //head pointed to node1
    Node* head = node1; //point
    print(head);

    InsertAtHead(head, 12);
    print(head);

    InsertAtHead(head, 15);
    print(head);

    InsertAtposition(head, 2, 25);
    print(head);

    return 0;
}