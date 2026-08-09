#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Node class
class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//builde bst from preorder
BinaryTreeNode* solve(vector<int> &preorder, int mini, int maxi, int &i){

    if(i >= preorder.size())
        return NULL;
    
    if(preorder[i] < mini  || preorder[i] > maxi)
        return NULL;

    BinaryTreeNode* root = new BinaryTreeNode(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}

// Inorder traversal
void inorder(BinaryTreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Preorder traversal
void preorderTraversal(BinaryTreeNode* root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){

    int n;
    cout<<"enter no. if elm:";
    cin>> n;

    vector<int> preorder(n);

    cout<<"Enter preorder Elements: ";

    for(int i=0; i<n;i++){
        cin>>preorder[i];
    }

    //create bst
    BinaryTreeNode * root = preorderToBST(preorder);

    cout<<" \n Original Preorder: ";
    for(int x : preorder){
        cout<< x <<" ";
    }

    cout<<"\nInorder of constructed BST:";
    inorder(root);

    cout<<"\nPreorder of constructed BST:";
    preorderTraversal(root);

    return 0;

}