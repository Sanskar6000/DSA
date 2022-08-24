//For flattening a linked list, we will use merge of merge sort recursively

Node* merge(Node* a, Node* b) {
    
    Node* temp = new Node(0);
    Node* ans = temp;
    
    while(a != NULL && b != NULL) {
        if(a -> data < b -> data) {
            temp -> bottom = a;
            temp = temp -> bottom;
            a = a -> bottom;
        }
        else {
            temp -> bottom = b;
            temp = temp -> bottom;
            b = b -> bottom;
        }
    }
    
    //Linking Remaining
    if(a) temp -> bottom = a;
    else temp -> bottom = b;
    
    return ans -> bottom;
}

Node *flatten(Node *root)
{
   //Using O(1) Space
   if(root == NULL || root -> next == NULL) return root;
   
   //Defining root's next
   root -> next = flatten(root -> next);
   
   root = merge(root, root -> next);
   
   return root;
}

