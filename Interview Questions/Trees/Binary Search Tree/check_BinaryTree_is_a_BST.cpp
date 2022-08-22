/*--------------------Binary Search Tree--------------------------*/
//In Binary Search Tree: 
//Elements to the right are strictly greater than root
//Elements to the left are strictly lesser than root

//Approach: We can pass Range for a number:
//For left: Range - [ val < Root]
//For right: Range - [val > Root]
//IMP!!!!!!!!!!! -> Use LONG MIN and LONG MAX

 bool isValidBST(TreeNode* root) {
        return checkforBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool checkforBST(TreeNode* root, long l, long r) {
        if(root == NULL) return true;
        if(root -> val >= r || root -> val <= l) return false;
        
        //Check for left
        bool lf = checkforBST(root -> left, l, root -> val);
        
        //Check for right
        bool rt = checkforBST(root -> right, root -> val, r);
        
        return lf && rt;
    }