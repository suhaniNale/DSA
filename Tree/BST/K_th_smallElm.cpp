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

void inorder(Node * root){
    if(root== NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
}

Node * insertInBST(Node * root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if( d  >  root->data){
        //right part
        root->right = insertInBST(root->right, d);
    }
    else{
        root->left = insertInBST(root->left ,d);
    }
    return root;
}

void takeInput(Node * &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

//find k th smallest element ->TC = O(n)  and SC = O(h)
int solve(Node * root, int & i ,int k){
    if(root == NULL)
        return -1; // wapus prev node vrti jaycha

    //inorder->LNR
    //1.left
    int left = solve(root->left, i, k);

    if(left != -1)
        return left;

    //2.k th node print
    i++;
    if(i==k){
        return root->data;
    }

    //3. right
    return solve(root->right, i, k);
}

int kthsmallest(Node * root, int k){
    int i=0;
    int ans = solve(root, i, k);
    return ans;
}

int main (){

    Node * root = NULL;

    cout<<"enter data to create BST: \n";  //5 4 8 2 6 10 3 7 -1   
    takeInput(root);

    cout<<"\nInorder Traversal of BST : ";
    inorder(root);

    int k;
    cout<<"\n Enter value of K: ";
    cin>>k;

    int ans = kthsmallest(root, k);

    if(ans == -1)
        cout<<"Invalid value of k";
    else
        cout<< k <<" th smallest element s :"<< ans;

    return 0;

}