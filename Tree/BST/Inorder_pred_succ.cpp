#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }

    if (d < root->data)
        root->left = insertIntoBST(root->left, d);
    else
        root->right = insertIntoBST(root->right, d);

    return root;
}

// Take Input
void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//inorder predecessor and successor->TC=O(n)  and SC = O(1)
pair<int, int> predecessorSuccessor(Node * root, int key){

    //find key
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp != NULL && temp->data != key){

        if(temp->data  > key){
            //left part
            succ = temp->data ;
            temp = temp->left;
        }
        else{
            pred = temp->data ;
            temp = temp->right;
        }
    }
    //if key not found
    if(temp == NULL){
        return  {pred, succ};
    }

    //pred and succ
    Node * leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;    //left tree madhle max elm  
    }

    Node * rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree ->data;
        rightTree= rightTree->left;
    }

    return {pred, succ};
}

int main() {

    Node *root = NULL;

    cout << "Enter BST elements (-1 to stop): ";
    takeInput(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    int key;
    cout << "\nEnter key: ";
    cin >> key;

    pair<int, int> ans = predecessorSuccessor(root, key);

    cout << "Predecessor: " << ans.first << endl;
    cout << "Successor: " << ans.second << endl;

    return 0;
}