class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // using BFS
        if(root == NULL) return {};

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            int maxEle = INT_MIN;
            while(n--) {
                TreeNode* node = que.front();
                que.pop();
                maxEle = max(maxEle, node->val);

                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
            }
            ans.push_back(maxEle);
        }
        return ans;
    }
};