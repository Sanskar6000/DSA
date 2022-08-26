//We will construct left tree only when the value of left is less than root's value and vice versa for right tree
    
TreeNode* bstFromPreorder(vector<int> &preorder) {
    int i = 0;
    return bst(preorder, INT_MAX, i);
}
    
TreeNode* bst(vector<int>& preorder, int bound, int &i) {
        
    if(i == preorder.size() || bound < preorder[i]) return NULL;
        
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    root -> left = bst(preorder, root -> val, i);
    root -> right = bst(preorder, bound, i);
        
    return root;
}