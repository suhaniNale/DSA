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

//LOT
void levelorder(Node * root){

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node * temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}
Node* insertToBST(Node* &root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    
    if(d > root->data){
        //right part
        root->right = insertToBST(root->right, d);
    }
    else{
        //left part
        root->left = insertToBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertToBST(root, data);
        cin>>data;
    }
}

int main() {

    Node* root = NULL;

    cout<<"enter data to create BST : ";  //50 30 70 20 40 60 80 -1
    takeInput(root);

    cout<<"printing the BST output : "<<endl;
    levelorder(root);

    
    return 0;


}