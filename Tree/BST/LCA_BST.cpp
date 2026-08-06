#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }

    if (d < root->data)
        root->left = insertIntoBST(root->left, d);
    else
        root->right = insertIntoBST(root->right, d);

    return root;
}

// Take Input
void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search a node in BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Lowest Common Ancestor in BST
Node* LCAinaBST(Node *root, Node *P, Node *Q) {

    if (root == NULL)
        return NULL;

    // Both nodes are in right subtree
    if (root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);

    // Both nodes are in left subtree
    if (root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);

    // Split point
    return root;
}

// Main Function
int main() {

    Node* root = NULL;

    cout << "Enter BST elements (-1 to stop): ";
    takeInput(root);

    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;

    int x, y;
    cout << "\nEnter two node values: ";
    cin >> x >> y;

    Node* P = search(root, x);
    Node* Q = search(root, y);

    if (P == NULL || Q == NULL) {
        cout << "One or both nodes are not present in the BST." << endl;
        return 0;
    }

    Node* ans = LCAinaBST(root, P, Q);

    if (ans != NULL)
        cout << "Lowest Common Ancestor: " << ans->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}