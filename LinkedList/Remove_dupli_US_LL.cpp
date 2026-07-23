#include <iostream>
#include <map>
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
//del from Un-sorted LL
Node * removeDuplicate(Node* head){
    if(head == NULL) {
        return NULL;
    }

    map<int , bool> visited;

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        //dupli node
        if(visited[curr->data] == true){

            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;

        }
        
    }
    return head;
}

int main() {

    Node* node1 = new Node(10);

    Node* head = node1; //point head
    Node* tail = node1;


    InsertAtTail(tail, 20);

    InsertAtTail(tail, 40);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 10);
    InsertAtTail(tail, 20);

    cout<<"Before Removing Duplicates: ";
    print(head);

    head = removeDuplicate(head);

    cout<<"After Removing Duplicates: ";
    print(head);
    
    return 0;
}