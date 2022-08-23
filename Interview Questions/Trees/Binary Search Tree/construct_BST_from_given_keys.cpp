//find Mid
//Make new node from mid
//Recusively call for left
//Recursuvely call for right
//Return root

TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    if(nums.size() == 0) return NULL;
    if(nums.size() == 1) return new TreeNode(nums[0]);
        
    int mid = (nums.size())/2;
        
    TreeNode* node = new TreeNode(nums[mid]);
        
    //IMP!!!!!!!!!!!!!!!!!!
    vector<int> l(nums.begin(), nums.begin() + mid);
    vector<int> r(nums.begin() + mid + 1, nums.end());
    node -> left = sortedArrayToBST(l);
    node -> right = sortedArrayToBST(r);
        
    return node;
}