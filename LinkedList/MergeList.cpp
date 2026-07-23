#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

//insert at tail
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next  = temp;
    tail = temp;
}
//print list

void print(Node* head){
    while(head != NULL){
        cout<< head->data <<" ";
        head = head-> next;
    }
    cout<< endl;

}

// merge second list into first list 
Node* solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = curr1 -> next;

    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    // if first list has only one node
    if (next1 == NULL) {
        curr1->next = curr2;
        return first;
    }

    while(next1 != NULL && curr2 != NULL){

        if((curr2 -> data >= curr1-> data  ) && (curr2 -> data <= next1->data))
        {
            //insert in between 
            next2 = curr2-> next;
            
            curr1 -> next = curr2 ;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1-> next;

            //if end of 1st list
            if(next1== NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;


}

Node* sortTwoLists(Node*  first , Node* second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }

    if(first -> data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}

int main(){

    //1st list
    Node* head1 = new Node(1);
    Node* tail1 = head1;

    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);
    cout<<"List1 : ";
    print(head1);

    //list 2
    Node* head2 = new Node(2);
    Node* tail2 = head2;

    insertAtTail( tail2, 4);
    insertAtTail(tail2, 6);
    
    cout<<"List2 : ";
    print(head2);

    //   MERGE
    Node* mergedList = sortTwoLists(head1, head2);

    cout<<"MERGED List : ";
    print(mergedList);

    return 0;
}
