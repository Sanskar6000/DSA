//Approach: Same aws Vertical Order Traversal
//The first node of every vertical will be my top view
 vector<int> topView(Node *root)
    {
        //First Node of every vertical will be my top view
        map<int, int> m;
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        while(!q.empty()) {
            auto top = q.front();
            Node* nde = top.first;
            int vertical = top.second;
            q.pop();
            if(m.find(vertical) == m.end()) m.insert({vertical, nde -> data});
            
            //Check left
            if(nde -> left) {
                q.push({nde -> left, vertical - 1});
            }
            
            //Check right
            if(nde -> right) {
                q.push({nde -> right, vertical + 1});
            }
        }
        
        vector<int> ans;
        for(auto p : m) {
            ans.push_back(p.second);
        }
        return ans;
    }