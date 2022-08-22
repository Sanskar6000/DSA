//Same as Height: recur -> 1 + l + h
//Diameter at given point -> left + right + 1
//Hence, diameter at given point -> left + right + 1
    int diameter = 0;
    
    int height(TreeNode* root) {
        if(!root) return 0;
        
        int l = height(root -> left);
        int r = height(root -> right);
        
        diameter = max(diameter, l + r);
        
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int temp = height(root);
        return diameter;
    }