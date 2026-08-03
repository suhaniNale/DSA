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

class Solution{
    private:
        unordered_map<int, int> mp;

        Node * solve(vector<int> &inorder, vector<int> &postorder,
            int &postIndex, int inStart, int inEnd)
        {
            //base case
            if(postIndex < 0  || inStart> inEnd)
                return NULL;
            
            //create root node
            int elm = postorder[postIndex--];
            Node * root = new Node(elm);
            
            //find position in inorder
            int position = mp[elm];

            //build right subtree first -> in postorder(LRN)  we are start from end
            root->right = solve(inorder, postorder, postIndex, position+1,inEnd);
            //left subtree
            root->left = solve(inorder, postorder, postIndex,inStart, position-1);

            return root;

        }
    public:
        Node * buildTree(vector<int> &inorder, vector<int> &postorder){

            int n = inorder.size();

            //store inorder indices
            for(int i=0; i<n;i++){
                mp[inorder[i]] = i;
            }

            int postIndex = n-1;

            return solve(inorder, postorder, postIndex,0, n-1);
        }
};

void levelOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        while(size--){
            Node * temp = q.front();
            q.pop();

            cout<< temp->data<< " ";

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

int main() {
    vector<int> inorder = {4, 2, 5, 1, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};

    Solution obj ;

    Node * root = obj.buildTree(inorder, postorder);

    cout<<"Level Order Traversal: \n";
    levelOrder(root);

    return 0;
}