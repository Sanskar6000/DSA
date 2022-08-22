//Find heights of left and right
//ans = ans && (abs(left - right) <= 1)
bool ans = true;
    
    int height(TreeNode* root) {
        if(!root) return 0;
        
        int l = height(root -> left);
        int r = height(root -> right);
        cout << l << " " << r << endl;
        ans = ans && (abs(l - r) <= 1);
        
        return 1 + max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int temp = height(root);
        return ans;
    }