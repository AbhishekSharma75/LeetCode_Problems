class Solution {
public:
    int currNum = 0; 
    int currFreq = 0;
    int maxFreq = 0;
    vector<int> ans;

    void dfs(TreeNode* root) {
        if(!root) return;

        dfs(root->left);

        if(root->val == currNum) {
            currFreq++;
        }
        else {
            currNum = root->val;
            currFreq = 1;
        }

        if(currFreq > maxFreq) {
            ans = {};
            maxFreq = currFreq;
        }

        if(currFreq == maxFreq) {
            ans.push_back(root->val);
        }
            
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};