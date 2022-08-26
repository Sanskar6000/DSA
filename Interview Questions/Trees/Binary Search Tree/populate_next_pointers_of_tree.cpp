//Push NULL to maintain deapth information O(N) space, O(N) time 
Node* connect(Node* root) {
    if(!root) return NULL;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
        
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
            
        if(node == NULL) {
            //If node is null
            //after getting it removed we need to push another null for elements in the queue
            if(q.size() > 0) q.push(NULL);
        }
        else {
            node -> next = q.front();
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
    }
        
    return root;
}