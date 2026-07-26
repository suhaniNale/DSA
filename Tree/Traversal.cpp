#include <iostream>
#include <queue>  
using namespace std;


class Node {

    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            this->data = d;
            this->left =  NULL;
            this->right =  NULL;
        }
};

Node * buildTree(Node * root){
    int data;
    cout<<"Enter the Data -> ";
    cin>>data;

    root = new Node(data);

    if(data== -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<< data <<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for inserting right of " <<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void  inorder(Node * root) {
    // LNR
    //base case
    if( root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node * root) {
    // NLR
    //base case
    if( root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node * root) {
    // LRN
    //base case
    if( root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {

    Node * root = NULL;

    root = buildTree(root);

    cout<<"inorder traversal-> ";
    inorder(root);
    cout<<endl;

    cout<<"preorder traversal-> ";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversal-> ";
    postorder(root);
    cout<<endl;
    
    return 0;
}