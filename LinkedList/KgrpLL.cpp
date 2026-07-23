#include <iostream>
using namespace std;

//reverse LL in k Grps
class Node{
    public:
    int data;
    Node * next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

Node* kReverse(Node* head , int k){
        //base call
        if(head==NULL){
            return NULL;
        }

        //step1: rev 1st k nodes
        Node* next = NULL;
        Node* curr = head;
        Node* prev = NULL;

        int count = 0;

        while(curr != NULL  && count < k){
            next = curr -> next ;
            curr -> next = prev;
            prev = curr;
            curr =next;
            count++;
        }

        //step 2: recursion will see upnext part
        if(next != NULL){
            head-> next = kReverse(next , k);
        }

        //step 3:return headf of the rev list
        return prev;

}
//print list
void print(Node* head ){
    while( head != NULL){
        cout<< head->data<<" ";
        head = head->next;
    }
    cout<<endl;

}
int main() {
    //creating LL
    Node*  head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout<<" Original LL :";
    print(head);

    head= kReverse(head, 2);

    cout<<" Afterk Reverse LL :";
    print(head);

    
    return 0;
}