class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int ans = 0;
        
        while(q.size()) {
            auto [cur, isLeft] = q.front(); q.pop();
            if(!cur -> left && !cur -> right && isLeft) 
                ans += cur -> val;
            if(cur -> right) q.push({cur -> right, false});
            if(cur -> left) q.push({cur -> left, true});
        }

        return ans;
    }
};