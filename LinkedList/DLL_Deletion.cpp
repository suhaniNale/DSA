#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this-> data = d;
        this-> prev = NULL;
        this-> next = NULL;
    }

    //destructor
    ~Node(){
        int val =  this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<< "Memory free for node with data" <<val<<endl;
    }
};
//traversing
void print(Node* head) {
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data<<" ";
        temp = temp -> next;
    }
    cout <<endl;
}
//length of LL
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead (Node* &head , int d){
    //empty list
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
  
}

void insertAtTail(Node* &tail, int d){
    //empty list
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

    }
    
}

void insertAtPosition(Node* &tail,Node* &head, int position, int d)
{
    if(position==1){
        insertAtHead(head, d);
        return;
    }

    Node* temp= head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }
    //insert at last posi
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);  //create
    nodeToInsert -> next = temp -> next;
    temp -> next ->prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(int position , Node* &head, Node* &tail ){
    //del 1st or last node
    if (position==1)
    {
        Node* temp = head;
        temp -> next ->prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position ){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr ->prev = NULL;
        prev -> next= curr -> next ;
        curr -> next  = NULL;
        delete curr;


        prev -> next = curr -> next;
        // 🔥 IMPORTANT: if last node is deleted
        if(curr -> next== NULL){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;

    }
    
    
}
int main() {
    Node* node1 = new Node(10);
    Node* head = node1 ; 
    Node* tail = node1 ;         //point 

    //Node* head = node1 ; 
    //Node* tail = node1 ;  
    
    print(head);
    //cout<<"Length :"<<getLength(head)<< endl;

    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 13);
    print(head);

    insertAtTail(tail, 9);
    print(head);

    insertAtPosition(tail, head, 3 , 45);
    print(head);

    // deleteNode(1, head,tail); //first
    // print(head);
    // cout<<"Head: "<<head->data<<endl;
    // cout<<"Tail: "<<tail->data<<endl;

    // deleteNode(3, head,tail);
    // print(head);
    // cout<<"Head: "<<head->data<<endl;
    // cout<<"Tail: "<<tail->data<<endl;

    deleteNode(6, head, tail);
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;


    
    return 0;
}