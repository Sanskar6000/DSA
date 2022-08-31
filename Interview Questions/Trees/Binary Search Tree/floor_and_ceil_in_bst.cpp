void calculate(TreeNode<int>* root, int X, int &floor, int &ceil) {
    while(root) {
        if(root -> val == X) {
            floor = root -> val;
            ceil = root -> val;
            return;
        }
        if(root -> val < X) {
            floor = root -> val;
            root = root -> right;
        }
        else {
            ceil = root -> val;
            root = root -> left;
        }
    }
    return;
}

int floorInBST(TreeNode<int> * root, int X)
{    
    int floor = -1, ceil = -1;
    calculate(root, X, floor, ceil);
    return floor;
}
