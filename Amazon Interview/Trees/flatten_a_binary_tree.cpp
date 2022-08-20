//We will Perform Traversal as -> Right, Left, Root
//Take a temporary Previous node
//Attach Previous Accordingly to nodes
//Then update Previous ;)
TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        flatten(root -> right);
        flatten(root -> left);
        
        //We are at extreme right
        root -> right = prev;
        root -> left = NULL;
        prev = root;
    }