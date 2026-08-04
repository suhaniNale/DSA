#include <iostream>

using namespace std;

class Node {
    public:
    
    int data;
    Node* left ;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
    public:
    void  flatten(Node * root){
        Node * curr = root;

        while(curr != NULL){
            // If left subtree exists
            if(curr->left){
                Node * pred = curr->left;
                while(pred->right)
                    pred=pred->right;
                
                //connect pred with curr's right subtree
                pred->right= curr->right;
                // Move left subtree to righ
                curr->right = curr->left;
                curr->left = NULL;     // Make left child NULL
            }
            //If left subtree NOT exists->move to next node
            curr = curr->right;
        }
    }
};

void printList(Node * root){
    while(root != NULL){
        cout<< root->data <<" ";
        root= root->right;
    }
}
int main(){

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution obj ;
    obj.flatten(root);

    cout<<"Flatten Linked list: ";
    printList(root);

    return 0;
}