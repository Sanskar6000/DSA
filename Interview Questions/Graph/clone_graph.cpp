//We will make a array having all initial values as NULL
//Then perform dfs subsequenty assigning new nodes to the array

void dfs(Node* node, vector<Node*> &ans) {
   
        ans[node -> val] = new Node(node -> val);
        
        //Iterating neighbors
        for(auto it : node -> neighbors) {
            //If not visisted perform dfs
            if(ans[it -> val] == NULL) {
                dfs(it, ans);
            }
            //Push neighbour
            ans[node -> val] -> neighbors.push_back(ans[it -> val]);
            // ans[node -> val] -> neighbors.push_back(it); ***We need copy not original***
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
    
        vector<Node*> ans(101);
        
        for(int i = 0; i <= 100; i++) {
            ans[i] = NULL;
        }
        dfs(node, ans);
        
        //Given node will always be the first node with value 1
        return ans[1];
    }