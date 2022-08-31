//Keep a counter as we go left decrease a counter by 1
TreeNode* inorder(TreeNode* root, int &k) {
        
        if(root == NULL) return NULL;
        
        TreeNode* left = inorder(root -> left, k);
        if(left != NULL) return left;
        k--;
        if(k == 0) return root;
        
        return inorder(root -> right, k);
}
    
int kthSmallest(TreeNode* root, int k) {
    //Inorder
 
    TreeNode* ans = inorder(root, k);
    return ans -> val;
    // return in[k - 1];    
}

//For largest
TreeNode* inorder(TreeNode* root, int &k) {
        
        if(root == NULL) return NULL;
        
        TreeNode* left = inorder(root -> right, k);
        if(right != NULL) return right;
        k--;
        if(k == 0) return root;
        
        return inorder(root -> right, k);
}