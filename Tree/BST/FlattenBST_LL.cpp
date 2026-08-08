#include <iostream>
#include <vector>
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

Node * insertInBST(Node * root, int d){
    if(root == NULL){
        return new Node(d);
    }

    if( d  >  root->data){
        root->right = insertInBST(root->right, d);
    }
    else{
        root->left = insertInBST(root->left, d);
    }

    return root;
}
void takeInput(Node * & root){
    int data ;
    cin>> data;

    while( data != -1){
        root = insertInBST(root , data);
        cin>>data;
    }
}

//inorder trav
void inorder(Node * root, vector<int> & arr){
    if (root == NULL)
        return;
    
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node * flatten(Node* root){

    vector <int> inorderVal;
    //1.store Inorder trav val in arr
    inorder(root , inorderVal);
    int n = inorderVal.size();

    if(n==0)
        return NULL;

    // Create first node
    Node * newRoot = new Node(inorderVal[0]);

    Node * curr = newRoot;

    //create remaining nodes
    for(int i=1; i<n; i++){
        Node * temp = new Node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;

        curr = temp;

    }

    //last node
    curr->left =NULL;
    curr->right = NULL;

    return newRoot;
}

//print flattened tree
void print(Node* root){

    while(root!=NULL){
        cout<< root->data <<" ";
        root= root->right;
    }
    cout<<endl;
}

int main() {

    Node* root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Node * ans = flatten(root);
    print(ans);

    return 0;
}