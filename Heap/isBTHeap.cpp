#include <iostream>
using namespace std;


// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
// Count total number of nodes
int countNodes(Node * root){
    if(root == NULL){
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT (Node * root, int index ,int cnt){
    if(root == NULL){
        return true;
    }
    if(index >= cnt){
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        return (left && right);
    }
}

bool isMaxOrder(Node * root){
    // Empty tree
    if (root == NULL) {
        return true;
    }
    //1. leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    //2. only left node
    if(root->right == NULL)
        return (root->data > root->left->data);

    //3. both node exist
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && 
            (root->data > root->left->data  && root->data > root->right->data));
    }   
}

bool isHeap(Node * tree){

    int index = 0;
    int totalCnt = countNodes(tree);

    if(isCBT(tree, index, totalCnt)  && isMaxOrder(tree) ){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node * root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(40);

    root->left->left = new Node(10);
    root->left->right = new Node(20);

    root->right->left = new Node(35);

    if(isHeap(root)){
        cout<<" the Binary Tree is Max Heap."<<endl;
    }
    else{
        cout<<" the Binary Tree is Not Max Heap."<<endl;
    }


    return 0;
}