#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this->data ;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout<< "Memory is free for node with data  "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list

        Node* curr = tail;

        while(curr->data != element){
            curr = curr ->next;
        }

        //elem found=> curr is representing elem wala node
        //insertion in circular LL
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail){

    Node* temp = tail;

//traversing
    do{
        cout<< tail -> data << " ";
        tail= tail->next;
    }while(tail !=temp );

    cout<<endl;
}

// delete node
void deleteNode(Node* &tail, int value){
    //handle empty list
    if(tail == NULL){
        cout<<"list is empty... please check again! "<<endl;
        return;
    }
    else{
        //non-empty list
        Node* prev = tail;
        Node* curr =prev ->next;

        while(curr -> data != value){
            prev = curr;
            curr = curr->next;
        }

        prev -> next= curr -> next;
        //1 node LL
        if(curr == prev){
            tail = NULL;
        }

        else if(tail == curr){
            tail= prev;

        }
        curr -> next= NULL;
        delete curr;
    }
}

int main() {
    Node* tail = NULL;

    insertNode(tail , 5, 3);
    print(tail);
    insertNode(tail , 3, 5);   //search node 3 and insert 5 next to 3
    print(tail);
    insertNode(tail , 5, 7);
    print(tail);
    insertNode(tail , 5, 6);
    print(tail);

    insertNode(tail , 7, 9);
    print(tail);

    deleteNode(tail, 6);
    print(tail);
    deleteNode(tail, 9);
    print(tail);
    // deleteNode(tail, 3);
    // print(tail);


    return 0;
}