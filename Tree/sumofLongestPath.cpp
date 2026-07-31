#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Node {
    public:
         int data;
         Node * left; 
         Node * right;

         Node (int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
         }
};

Node * buildTree(Node * root){
    int data;
    cout<<"Enter the Data: ";
    cin>>data;

    if(data ==  -1){
        return NULL;
    }

    root = new Node(data);
    cout<<"Inserting data to the left of  : "<<data<<endl;
    root ->left = buildTree(root ->left);

    cout<<"Inserting data to the right of  : "<<data<<endl;;
    root ->right = buildTree(root ->right);

    return root;

}

class Solution {
    public:

        void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
            //base case
            if(root == NULL){

                if(len > maxLen){
                    maxLen = len;
                    maxSum = sum;
                }
                else if(len == maxLen){
                    maxSum = max (sum, maxSum);
                }
                return;
            }

            sum = sum + root -> data;
            //rec call
            solve( root->left, sum , maxSum , len+1, maxLen);
            solve( root->right, sum , maxSum , len+1, maxLen);
        }

        int sumOfLongRootToLeafPath(Node *root){

            int len = 0;
            int maxLen = 0;

            int sum = 0;
            int maxSum = INT_MIN;

            solve( root, sum , maxSum , len, maxLen);

            return maxSum;
        }
};

int main (){
    Node * root = NULL;

    cout<< "build the TREE : \n";
    root = buildTree(root);

    Solution obj ;
    int ans = obj.sumOfLongRootToLeafPath(root);

    cout<<"\nSum of Longest Root to Leaf Path = " << ans << endl;

    return 0;
}
