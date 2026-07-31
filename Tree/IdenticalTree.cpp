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

    cout<< " enter data to inserting on left of "<<data<<": ";
    root->left = buildTree(root->left);
    cout<< " enter data to inserting on right of "<<data<<" : ";
    root->right = buildTree(root->right);

    return root;

}

class Solution {

    public:

        bool isIdentical(Node* r1, Node* r2){
            //base case
            if(r1 == NULL  && r2 ==NULL){
                return true;
            }

            if(r1 == NULL  && r2 != NULL  || r1 != NULL  && r2 ==NULL)
            {
                return false;
            }

            bool left = isIdentical(r1->left , r2->left);
            bool right = isIdentical(r1->right , r2->right);

            bool curr_val = r1->data == r2->data ;

            if(left && right && curr_val){
                return true;
            }
            else{
                return false;
            }
        }
};

int main() {

    Node * r1 = NULL;
    Node * r2 = NULL;

    cout<<"Build 1st tree:\n";
    r1 = buildTree(r1);

    cout<<"build 2nd tree:\n";
    r2= buildTree(r2);

    Solution obj;

    if(obj.isIdentical(r1,r2)){
        cout<<"Trees are Identical";
    }
    else{
        cout<<"Trees are NOt Identical";
    }
    return 0;
}

