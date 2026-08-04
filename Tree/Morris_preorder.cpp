#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    
    int data;
    Node* left ;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Morris Preorder Traversal->visit before creating the node
vector<int> morrisPreorder(Node * root){

    vector<int> ans;
    Node * curr =root; 

    while(curr != NULL){

        if(curr->left == NULL ){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node * pred = curr->left;

            while(pred->right != NULL  && pred->right != curr)
                pred = pred->right;

            if(pred->right == NULL){
                ans.push_back(curr->data);  //visit before thread
                pred->right = curr;     // Create thread
                curr = curr ->left;
            }
            else{
                pred->right = NULL;  //remove thread
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = morrisPreorder(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}
