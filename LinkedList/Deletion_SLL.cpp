#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){     
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is  free for node with data "<<value<<endl;
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

void deleteNode(int position , Node* &head, Node* &tail){
    //del start node
    if(position == 1){
        Node* temp = head;
        head = head-> next ;  //head shifted to nxt posi

        if(head == NULL){  // if only one node was present
            tail == NULL;
        }

        temp -> next = NULL;
        delete temp; 
    }
    else{
        //del mid or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

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

    Node* head = node1; //point head
    Node* tail = node1;
    print(head);

    InsertAtTail(tail, 20);
    print(head);

    InsertAtTail(tail, 30);
    print(head);

    InsertAtTail(tail, 40);
    print(head);

    cout<<"head:"<<head ->data <<endl;
    cout<<"tail:"<<tail ->data <<endl;

    deleteNode(4 , head, tail );
    print(head);

    cout<<"head:"<<head ->data <<endl;
    cout<<"tail:"<<tail ->data <<endl;

    return 0;
}