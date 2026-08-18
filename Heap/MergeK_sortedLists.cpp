#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
    int data ;
    Node * next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

//comparator
class Compare{
    public:
        bool operator()(Node* a, Node * b){
            return a->data > b->data;
        }
};

Node * mergeKLists(vector<Node*> & lists){
    //min heap 
    priority_queue<Node* , vector<Node*>, Compare> minHeap;

    //step1:insert 1st node of each  LL 
    for(int i = 0; i<lists.size(); i++){
        if(lists[i] != NULL){
            minHeap.push(lists[i]);
        }
    }
    //Dummy node
    Node * dummy  = new Node(-1);

    Node * tail = dummy;

    // Step 2:
    // Process Min Heap
    while(!minHeap.empty()){
        //get smallest node
        Node* smallest = minHeap.top();
        minHeap.pop();

        // Add smallest node to answer
        tail->next = smallest;
        tail = smallest;

        //if next node exists->insert it into min Heap
        if(smallest->next != NULL){
            minHeap.push(smallest->next);
        }
    }
    //store ans
    Node * head = dummy->next;

    //delete dummy node
    delete dummy;

    return head;

}

void printList(Node * head){
    while(head != NULL){
        cout<< head->data;

        if(head->next != NULL){
            cout<<" -> ";
        }
        head = head->next;
    }
    cout<<endl;
}
int main() {

    //l1
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(7);

    //l2
    Node* list2 = new Node(2);
    list2->next = new Node(5);
    list2->next->next = new Node(8);

    //l3
    Node* list3 = new Node(3);
    list3->next = new Node(6);
    list3->next->next = new Node(9);

    vector<Node*> lists= {
        list1,
        list2,
        list3
    };

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    cout << "List 3: ";
    printList(list3);

    //merge
    Node * result = mergeKLists(lists);

    cout<<" Merged List : ";
    printList(result);

    return 0;
}