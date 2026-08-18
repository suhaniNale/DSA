#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d ;
            left = right = nullptr;
        }
};

void inorderTraversal(Node* root, vector<int> &in){
    if(root==NULL){
        return;
    }

    inorderTraversal(root->left, in);
    in.push_back(root->data);
    inorderTraversal(root->right, in);
}

// Function to perform preorder traversal of the tree
// and copy the values from the inorder array to nodes
void preorderFill(Node* root, vector<int> &in, int &index){
    if(root==NULL){
        return;
    }
    //copt  next elm from inorder array
    root->data = in[index++];

    //fill l & r subtree
    preorderFill(root->left, in, index);
    preorderFill(root->right, in, index);
}

void convertBSTtoMinHeap(Node* root){

    vector<int> in;
    //1.store values in inorder ->sorted
    inorderTraversal(root, in);

    int index = 0;

    //2.pre trav->to fill nodes with inorder val
    preorderFill(root, in, index);

}
// Function to print preorder traversal of the tree
void printPreorder(Node * root){
    if(root==NULL){
        return;
    }

    cout<< root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){

    //constructing BST
    Node * root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTtoMinHeap(root);
    printPreorder(root);

    return 0;

}