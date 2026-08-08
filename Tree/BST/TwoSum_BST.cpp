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

bool twoSumBST(Node * root , int target){

    vector<int> arr;
    inorder(root, arr);

    //use 2 ptr approach  to check sum exist
    int i =0;
    int j = arr.size() - 1;

    while (i<j)
    {
        int sum = arr[i] + arr[j];

        if(sum == target)
            return true;

        if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main () {

    Node * root = NULL;

    cout<<"Enter values to create BST : ";   //5 3 7 2 4 6 8 -1
    takeInput(root);

    int target;

    cout<<"enter target Sum: ";
    cin>>target;

    if(twoSumBST(root, target)){
        cout<<"pair exist "<<endl;
    }
    else{
        cout<<"pair does Not exist "<<endl;
    }

    return 0;
}