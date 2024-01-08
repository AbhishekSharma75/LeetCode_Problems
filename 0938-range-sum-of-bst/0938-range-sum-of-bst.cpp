class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        // within range 
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }

        // root->val < low (waste to go to left. so, we go right)
        if(root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        // root->val > high (waste to go to right. So, we go left)
        return rangeSumBST(root->left, low, high);
    }
};