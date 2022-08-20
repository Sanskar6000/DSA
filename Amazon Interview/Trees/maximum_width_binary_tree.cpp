//Approach
//Performing Level order traversal
//Assigning each node as 2*i + 1 & 2 * i + 2
//In order to prevent overflow: for each i make it (i - minValueatLevel)
//Width = LastIndex - FirstIndex + 1

int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        //Perform level order traversal
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long width = 0;
        while(!q.empty()) {
            long long mini = q.front().second; //mini will be 0 at first then it will be 1 constantly...
            
            long long first, last;
            long long size = q.size(); 
            for(int i = 0; i < size; i++) {
                TreeNode* curr_node = q.front().first;
                long long curr_index = q.front().second - mini;
                cout << "mini " << mini << endl;
                cout << "curr Index " << curr_index << endl;
                q.pop();
                //Set first and last nodes
                if(i == 0) {
                    first = curr_index;
                }
                if(i == size - 1) {
                    last = curr_index;
                }
                
                if(curr_node -> left) {
                    q.push({curr_node -> left , curr_index * 2 + 1});
                }
                if(curr_node -> right) {
                    q.push({curr_node -> right, curr_index * 2 + 2});
                }
            }
            width = max(width, last - first + 1);
        }
        
        return width;
    }
