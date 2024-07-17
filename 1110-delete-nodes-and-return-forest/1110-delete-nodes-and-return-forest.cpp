class Solution {
public:
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        if(root == NULL) return NULL;

        root->left = deleteHelper(root->left, st, ans);
        root->right = deleteHelper(root->right, st, ans);

        if(st.find(root->val) != st.end()) {
            if(root->left != NULL) {
                ans.push_back(root->left);
            }
            if(root->right != NULL) {
                ans.push_back(root->right);
            }
            return NULL;
        }
        else {
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        for(int &num : to_delete) {
            st.insert(num);
        }
        deleteHelper(root, st, ans);

        if(st.find(root->val) == st.end()) {
            ans.push_back(root);
        }

        return ans;
    }
};