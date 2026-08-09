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

//to merge two bst   -> TC ->O(m+n)
//sttep 1 inorder trav 
void inorder(Node * root, vector<int> &in){
    if(root==NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

//step 2.merge 2 sorted arr
vector<int> mergeArrays(vector<int> &a , vector<int> &b){

    vector<int> ans(a.size() + b.size());

    int i =0, j=0;
    int k=0;

    while(i < a.size()  && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }
    //remaining elem of a
    while(i <a.size()){
        ans[k++] = a[i];
            i++;
    }
    //remaining elem of b
    while(i < b.size()){
        ans[k++] = a[j];
            j++;
    }

    return ans;
}
//step 3: sorted inorder array to balanced bst
Node * inorderToBST(int s, int e , vector<int> &in){
    if( s > e)
        return NULL;
    
    int mid = s + (e-s)/2;

    Node * root = new Node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;
}
//step 4: merge 2 bst
Node * mergeBST(Node* root1, Node* root2){

    vector<int> bst1, bst2;
    //1.store inorder
    inorder(root1, bst1);
    inorder(root2,bst2);

    //merge both inorder  sorted arr
    vector<int> mergeTWOArray= mergeArrays(bst1, bst2);

    int s=0;
    int e= mergeTWOArray.size()-1;

    return inorderToBST(s,e,mergeTWOArray);
}

Node * insertToBST(Node * root , int d){
    if(root == NULL){
        return new Node(d);
    }

    if(d < root->data){
        root->left = insertToBST(root->left, d);
    }
    else{
        root->right = insertToBST(root->right, d);
    }
    return root;
}

void takeInput(Node * &root){
    int data;
    cin>>data;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cin>>data;
    }   
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;

    cout<<"\n Enter Elements for BST 1: ";
    takeInput(root1);

    cout<<"\n Enter Elements for BST 2: ";
    takeInput(root2);

    cout<<"\n Inorder if BST 1: ";
    vector<int> arr1;
    inorder(root1, arr1);

    for(int x: arr1)
        cout<< x <<" ";
    
    cout<<"\nInorder for BST 2: ";
    vector<int> arr2;
    inorder(root2, arr2);
    for(int x : arr2)
        cout<< x<< " ";

    //merge BSTs
    Node * mergedRoot = mergeBST(root1, root2);

    //Inorder od merged bst
    cout<<" \n Inorder of merged bst :";
    vector<int> merged;
    inorder(mergedRoot, merged);

    for(int x : merged)
        cout<< x<<" ";

    cout<<endl;

    return 0;
}
