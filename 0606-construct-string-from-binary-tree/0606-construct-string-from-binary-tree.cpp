class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";

        string ans = to_string(root->val);  // root (L)(R)

        string left = tree2str(root->left);
        string right = tree2str(root->right);

        if(root->left == NULL && root->right == NULL) {   //"1"
            return ans;
        }
        if(root->left == NULL) {
            return ans + "()" + "(" + right + ")";
        }
        if(root->right == NULL) {
            return ans + "(" + left + ")";
        } 

        return ans + "(" + left + ")" + "(" + right + ")";
    }
};