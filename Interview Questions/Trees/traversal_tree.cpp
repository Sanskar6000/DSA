//Inorder, preorder, postorder traversal of trees
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left, *right;
};

//New Node function
struct Node* newNode(int data) {
    Node* temp = new Node;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void preorder(struct Node* node) {
    //Root Left Right
    
    if(node == NULL) return;

    cout << node -> data << " ";

    preorder(node -> left);

    preorder(node -> right);
}

void postorder(struct Node* node) {
    //Left Right Root

    if(node == NULL) return;

    postorder(node -> left);

    postorder(node -> right);
    
    cout << node -> data << " ";

}

void inorder(struct Node* node) {
    //Left Root Right

    if(node == NULL) return;

    inorder(node -> left);

    cout << node -> data << " ";

    inorder(node -> right);
}

int main() {
    struct Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);

    cout << "\nPreorder: \n";
    preorder(root);
    cout << "\nPostorder: \n";
    postorder(root);
    cout << "\nInorder: \n"; 
    inorder(root);
}

