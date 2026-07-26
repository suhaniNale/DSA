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

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<< " enter data to inserting on left of"<<data<<endl;
    root->left = buildTree(root->left);
    cout<< " enter data to inserting on right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

class Solution {
    public:
    //TC - O(n)   SC -> O(h)
        pair<bool , int> isBalancedFast(Node * root){

            if(root == NULL){
                pair<bool, int > p = make_pair(true, 0);
                return p;
            }

            pair<bool , int> left = isBalancedFast(root->left);
            pair<bool , int> right = isBalancedFast(root->right);

            bool leftAns = left.first;
            bool rightAns = right.first;

            bool diff = abs(left.second - right.second) <= 1;

            pair <bool , int > ans;
            ans.second = max(left.second , right.second) +1;

            if(leftAns  && rightAns  && diff){
                ans.first = true;
            }
            else{
                ans.first = false;
            }
            return ans;

        }

        bool isBalanced(Node * root){

            return isBalancedFast(root).first;
        }
};
int main() {

    Node * root = NULL;

    root = buildTree(root);

    Solution obj ;

    if(obj.isBalanced(root)){
        cout<<"Tree is Balanced."<<endl;
    }
    else{
        cout<<"Tree is NOT Balanced."<<endl;
    }


    return 0;
}