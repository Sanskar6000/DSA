 bool ans(TreeNode* left, TreeNode* right) {
           
        if(left == NULL || right == NULL) {
            return left == right;
        }
        if(left -> val != right -> val) {
            return false;
        }
        
         return ans(left -> right, right -> left) && ans(left -> left, right -> right);
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || ans(root -> left, root -> right);
    }
