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
            this->left = NULL;
            this->right = NULL;
        }
};

Node * buildTree(Node* root){

    int data;
    cout<<"Enter data: ";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<< " \nenter data to inserting on left of "<<data<<": ";
    root->left = buildTree(root->left);
    cout<< " \nenter data to inserting on right of "<<data<<" : ";
    root->right = buildTree(root->right);

    return root;

}

class Solution {
    public:
        Node * lca(Node* root , int n1 , int n2){

            if(root==NULL){
                return NULL;
            }

            if(root->data  == n1  || root->data  == n2){
                return root;
            }

            Node * leftAns = lca(root->left, n1,n2);
            Node * rightAns = lca(root->right, n1,n2);

            if(leftAns != NULL  && rightAns != NULL){
                return root;
            }
            else if(leftAns != NULL  && rightAns == NULL){
                return leftAns;
            }
            else if(leftAns == NULL  && rightAns != NULL){
                return rightAns;
            }
            else{
                return NULL;
            }
        }
};

int main(){

    Node * root = NULL;

    cout<<"Build the tree: \n";
    root = buildTree(root);

    int n1, n2;
    cout<<"Enter 1st Node:";
    cin>>n1;
    cout<<"Enter 2nd Node:";
    cin>>n2;

    Solution obj;
    Node * ans = obj.lca(root, n1,n2);

    if(ans != NULL){
        cout<<"LOWEST COMMON ANCESTOR IS :" <<ans->data<<endl;
    }
    else{
        cout << "\nOne or both nodes are not present in the tree." << endl;
    }

    return 0;
}