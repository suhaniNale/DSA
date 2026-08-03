#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>  
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

class Solution {
    private:
        unordered_map<int , int> mp;

        Node * solve(vector<int> &inorder, vector<int> &preorder, 
            int & preIdx, int inStart, int inEnd)
        {
            //base case
            if(preIdx >= preorder.size()  || inStart >inEnd)
                return NULL;
            
            //create root
            int elm = preorder[preIdx++];
            Node* root = new Node(elm);

            //find position of root in inorder
            int position = mp[elm];
            //left Subtree
            root ->left = solve(inorder, preorder,preIdx, inStart, position-1);
            //right subtree
            root ->right = solve(inorder, preorder,preIdx,  position+1, inEnd);

            return root;
        } 
        
    public:
        Node * buildTree(vector<int> &inorder, vector<int> &preorder){

            int n = inorder.size();
            
            //store inorder indices
            for(int i = 0; i<n; i++)
                mp[inorder[i]] = i;

            int preIdx = 0;

            return solve(inorder, preorder,preIdx, 0 , n-1);
        }
};

void levelTraversal (Node * root){
    if(root == NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        while(size--){
            Node * temp = q.front();
            q.pop();

            cout<< temp->data <<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
}

int main(){

    vector<int> inorder = {4,2,5,1,3};
    vector<int> preorder = {1,2,4,5,3};

    Solution obj;

    Node * root = obj.buildTree(inorder, preorder);

    cout<<"Level Order Traversal: \n";
    levelTraversal(root);

    return 0;
}