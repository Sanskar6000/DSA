TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> m;
    for(int i = 0; i < inorder.size(); i++) {
        m[inorder[i]] = i;
    }
        
    return buildTreePostin(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, m);
}

TreeNode* buildTreePostin(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &m) {
    if(inStart > inEnd || postStart > postEnd) return NULL;
        
    TreeNode* root = new TreeNode(postorder[postEnd]);
        
    int inRoot = m[postorder[postEnd]];
    int numleft = inRoot - inStart;
        
    root -> left = buildTreePostin(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numleft - 1, m);
    root -> right = buildTreePostin(inorder, inRoot + 1, inEnd, postorder, postStart + numleft, postEnd - 1, m);
        
    return root;
}