#include <iostream>
#include <map>
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
    // if(tail == NULL){  // empty list
    //     cout<<"empty list";
    //     return;
    // }
    

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

bool isCircularList(Node* head ){
    if(head == NULL){  // empty list
        return NULL;
    }

    Node* temp = head-> next;

    while(temp != NULL  && temp != head){
        temp = temp -> next;
    }

    // if(temp == NULL){
    //     return false;
    // }
    if(temp == head){
        return true;
    }
    return false;
}
// //detect the loop in LL
// bool detectLoop(Node* head){
//     //empty list
//     if(head==NULL)
//         return false;
    
//     map <Node* , bool > visited;

//     Node* temp = head;

//     if(temp != NULL)     //NON-Circular LL
//     {
//         //cycle is present
//         if(visited[temp] == true){
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp -> next;

//     }
//     return false;


// }

int main() {
    Node* tail = NULL;
    Node* head = NULL;


    if(isCircularList(tail)){
        cout<< "Linked list is Circular in nature"<<endl;

    }
    else{
        cout<< "Linked list is Not Circular in nature"<<endl;
    }

    return 0;
}