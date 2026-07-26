#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node *left , *right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void reverseLevelOrder (Node* root){
    if (root == NULL){
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while(!q.empty()) {
        Node * temp = q.front();
        q.pop();

        s.push(temp);

        //push right 1st then left node in queue
        if(temp -> right){
            q.push(temp->right);
        }
        if(temp -> left){
            q.push(temp->left);
        }
    }
    while(!s.empty()){
        cout<<s.top()->data <<" ";
        s.pop();
    }
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    reverseLevelOrder(root);

    return 0;
}