class Solution {
public:
    void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& ans) {
        for(int &ngbr : adj[currNode]) {
            if(ans[ngbr].empty() || ans[ngbr].back() != ancestor) {
                ans[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, ans);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        unordered_map<int, vector<int>> adj;
        for(vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++) {
            int ancestor = i;
            DFS(ancestor, adj, i, ans);
        }

        return ans;
    }
};