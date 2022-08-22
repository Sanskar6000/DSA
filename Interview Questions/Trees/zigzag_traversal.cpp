//Use Level order traversal
//Declare temp as temp(size);
//Use a flag when flag is false(that is reverse traversal)
// ind = size - i - 1;

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> tempvec(size);
            for(int i = 0; i < size; i++) {
                 TreeNode* temp = q.front();
                    q.pop();
                    
                int ind;
                if(flag) {
                   ind = i;
                }
                else {
                    ind = size - 1 - i;
                }
                
                tempvec[ind] = temp -> val;
                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            }
            flag = !flag;
            ans.push_back(tempvec);
        }
        return ans;
    }