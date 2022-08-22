//Recurrence Relation -> max(l, r) + root -> val
//Leaf node will give max(0, 0) + leaf -> val
//For taking care of negative values
//We will use l = max(0, recur(root -> left))

int ans = INT_MIN;
    
int solution(TreeNode* root) {
    if(root == NULL) return 0;
    
    //For taking care of negative values
    int l = max(0, solution(root -> left));
    int r = max(0, solution(root -> right));
        
    ans = max(ans, l + r + root -> val);
        
    return max(l, r) + root -> val;
}

int maxPathSum(TreeNode* root) {
    int temp = solution(root);
    return ans;
}