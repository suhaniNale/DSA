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
//del from sorted LL
Node * uniqueSortedList(Node * head){

    //TC=>O(n)     & SC => O(1)

    // 1-> 2-> 2->3 ->4
    if(head == NULL)  // empty list
    { 
        return NULL;
    }
    //non-empty list
    Node *  curr = head;

    while(curr != NULL){
        if ( (curr -> next != NULL)  && curr->data == curr->next ->data )
        {
            Node* next_next = curr -> next ->next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;  // not equal
        }
    }
    return head; 

}

int main() {

    Node* node1 = new Node(10);

    Node* head = node1; //point head
    Node* tail = node1;


    InsertAtTail(tail, 20);

    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);

    cout<<"Before Removing Duplicates: ";
    print(head);

    head = uniqueSortedList(head);

    cout<<"After Removing ṇDuplicates: ";
    print(head);
    
    return 0;
}