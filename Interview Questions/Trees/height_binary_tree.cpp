//recur -> 1 + max(l, r)
//Use Post-Order traversal
//Any leaf node will return 1 + max(0, 0)

int maxDepth(TreeNode* root) {
    if(!root) return 0;
        
    int l = maxDepth(root -> left);
    int r = maxDepth(root -> right);
        
    return 1 + max(l, r);
}