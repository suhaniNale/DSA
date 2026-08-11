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

//inorder
void inorder(Node * root){
    if(root== NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

//preorder
void preorder(Node * root){
    if(root==NULL){
        return;
    }

    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//postorder
void postorder(Node * root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";
}

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

//minimum value
Node* minVal(Node* &root)
{
    Node* temp = root;

    while(temp ->left != NULL){
        temp = temp->left;
    }
    return temp;
}
//maximum value
Node* maxVal(Node* &root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp -> right;
    }
    return temp;
}

//delete node
Node* deleteFromBST(Node* root, int val){
    //base case 
    if(root== NULL){
        return root;
    }

    if(root->data == val){
        //case 1 ->zero child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //case 2 -> left child present
        if(root->left != NULL && root->right == NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        //case 3 -> right child present
        if(root->left == NULL && root->right != NULL){
            Node * temp = root->right;
            delete root;
            return  temp;
        }
        //case 4 -> left and right  child present
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right) ->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        //left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        //right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
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

    cout<<"\nprinting the BST output : "<<endl;
    levelorder(root);

    cout<<"\nBST Inorder Traversal: ";
    inorder(root);

    cout<<"\nBST preorder Traversal: ";
    preorder(root);

    cout<<"\nBST postorder Traversal: ";
    postorder(root);

    cout<<"\nMinimum value :"<< minVal(root) ->data << endl;
    
    cout<<"\nMaximum value :" << maxVal(root) ->data <<endl;;

    root = deleteFromBST(root, 30);

    cout<<"\nprinting the BST output : "<<endl;
    levelorder(root);

    cout<<"\nBST Inorder Traversal: ";
    inorder(root);

    cout<<"\nBST preorder Traversal: ";
    preorder(root);

    cout<<"\nBST postorder Traversal: ";
    postorder(root);

    cout<<"\nMinimum value :"<< minVal(root) ->data << endl;
    
    cout<<"\nMaximum value :" << maxVal(root) ->data <<endl;;
    

    
    return 0;


}