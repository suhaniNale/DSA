#include <iostream>
#include <vector> 
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};
//morris traversal -> perform inorder and preorder traversal without using recursion or stack.
vector<int> morrisInorder(Node* root) {

    vector<int> ans;
    Node *curr = root;

    while(curr != NULL) {

        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else{
            //predecessor->rightmost node in left subtree
            Node * pred = curr->left;

            while(pred->right != NULL  && pred->right != curr){
                pred = pred->right;   
            }
            if(pred->right == NULL){

                pred->right = curr;     //create thread
                curr = curr->left;     
            }
            else{
                pred->right = NULL;     //remove thread
                ans.push_back(curr->data);
                curr = curr->right;

            }
        }
    }
    return ans;
}

int main() {

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = morrisInorder(root);

    for (int x : ans){
    	cout<< x << " " ;
	}
    
    return 0;

}

