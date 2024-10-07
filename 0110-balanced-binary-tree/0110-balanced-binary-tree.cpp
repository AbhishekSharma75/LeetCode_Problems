class Solution {
public:
    int dfsHeight(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);
        int rightHeight = dfsHeight(root->right);

        if(leftHeight == -1 || rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};