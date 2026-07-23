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
    tail = temp;
}

// for rearranging nodes
void InsertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
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

Node* sortList(Node * head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node*  oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node*  twoTail = twoHead;

    Node * curr = head;

    //create seperate list for 0's , 1's & 2's
    while (curr != NULL){

        int value = curr-> data;

        Node* nextNode = curr->next;
        curr->next = NULL;

        if(value == 0){
            InsertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            InsertAtTail(oneTail, curr);
        }
        else if(value == 2){
            InsertAtTail(twoTail, curr);
        }
        curr = nextNode;
    }

    //now merge 3 sublist 

    //1's list not empty     
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //setup head
    head = zeroHead ->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

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

    head = sortList(head);

    cout<<"After sorting: ";
    print(head);
    
    return 0;
}