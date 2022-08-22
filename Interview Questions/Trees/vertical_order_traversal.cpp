//Approach: Start with (0, 0) -> (Vertical, Level)
//When going left decrese vertical by -1 and increase level by +1
//When going right increase vertical by +1 and increase level by +1
//Apply BFS
//Store in a map as <vertical, nodes> -> one with least vertical will be first
//Final Data Structure: map<vertical, map<level, multiset<nodes>>>

vector<vector<int>> verticalTraversal(TreeNode* root) {
        //DS
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto t = q.front();
            auto node = t.first;
            int vertical = t.second.first;
            int level = t.second.second;
            q.pop();
            // /*********/ Accessing Multiset
            m[vertical][level].insert(node -> val);    
            
            if(node -> left) {
                q.push({node -> left, {vertical - 1, level + 1}});
            }
             if(node -> right) {
                q.push({node -> right, {vertical + 1, level + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto i : m) {
            vector<int> temp;
            for(auto j : i.second) {
                /***********/
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
