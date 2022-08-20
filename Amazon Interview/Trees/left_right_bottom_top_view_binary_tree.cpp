//Left/Right view of Binary Tree
//Method 1: Use Root Left Right for left view and Root Right Left for Right View (if level == datastructure.size) push the node
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* temp = new Node;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
}

void leftview(struct Node* root, vector<int> &ans, int level) {

    //Base Case
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root -> data);

    leftview(root -> left, ans, level + 1);
    leftview(root -> right, ans, level + 1);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);

    vector<int> ans;
    leftview(root, ans, 0);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    // vector<int> rv;
    // rightview(root, rv);
}