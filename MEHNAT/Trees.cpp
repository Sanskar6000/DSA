#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void insert(Node* &root, int val) {
    Node* newNode = new Node(val);
    if(root == NULL) {
        root = newNode;
        return;
    }

    Node* prev = NULL;
    Node* temp = root;
    while(temp) {
        if(temp -> data > val) {
            prev = temp;
            temp = temp -> left;
        }
        else {
            prev = temp;
            temp = temp -> right;
        }
    }

    if(prev -> data > val) {
        prev -> left = newNode;
    }
    else {
        prev -> right = newNode;
    }
}

//BST Iterator
class BSTIterator {
    private:
    stack<Node*> st;

    public:
    //Constructor
    BSTIterator(Node* root)
    {
        Node* curr = root;
        while(curr != NULL) {
            st.push(curr);
            curr = curr -> left;
        }
    }

    int next() {
        Node* temp = st.top();
        st.pop();
        Node* curr = temp -> right;
        while(curr != NULL) {
            st.push(temp);
            temp = temp -> left;
        }
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    Node* root = NULL;
    insert(root, 30);
    insert(root, 50);
    insert(root, 15);
    insert(root, 20);
    insert(root, 19);
    insert(root, 45);
    insert(root, 36);


}