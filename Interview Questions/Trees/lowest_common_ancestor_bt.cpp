//Brute: Find Path of both nodes from tree-> traverse each path
//Approach: Use Preorder Traversal
//if we find NULL, first Node or Second Node return it
//If left and right both are not NULL. Then the corresponding root will be our answer 

//Brute
 bool pathArr(TreeNode* root, TreeNode* node, vector<TreeNode*> &arr) {
        //If root is NULL return false
        if(root == NULL) return false;
        
        
        arr.push_back(root);
        if(root -> val == node -> val) return true;
        
        //Check left and right sub trees
        if(pathArr(root -> left, node, arr) || pathArr(root -> right, node, arr)) return true;
        
        arr.pop_back();
        return false;
    } 
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Brute Force store paths of both nodes in an array then match
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;
        
        pathArr(root, p, pv);
        pathArr(root, q, qv);
        
        //Checking each node
        int i = 0;
        while(i < pv.size() && i < qv.size()) {
            cout << pv[i] -> val << " " << qv[i] -> val << endl;
            if(pv[i] -> val != qv[i] -> val) break;
            i++;
        }
        
        return pv[i - 1];
    }

//Time Complexity: O(N) + O(N) + O(N)
//Space: O(N)

//Optimised Algorithm
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        //When a node gets two nodes which are not NULL
        else {
            return root;
        }
    }