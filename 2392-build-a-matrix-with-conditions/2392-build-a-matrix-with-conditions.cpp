class Solution {
public:
    void dfs(int u, vector<int>& visited, unordered_map<int, vector<int>>& adj, stack<int>& st, bool &cycle) {
        visited[u] = 1;
        for(int &v : adj[u]) {
            if(visited[v] == 0) {
                dfs(v, visited, adj, st, cycle);
            }
            else if(visited[v] == 1) {
                cycle = true;
                return;
            }
        }
        visited[u] = 2; // visited
        st.push(u);
    }

    vector<int> toptSort(vector<vector<int>>& edges, int &n) {
        // make adjacency list (graph)
        unordered_map<int, vector<int>> adj;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> visited(n+1, 0);  // nodes k values = 1, 2, ..., n
        stack<int> st; // u -> v
        // {u, v1, v2, v}
        vector<int> order;
        bool cycle = false;
        for(int i = 0; i <= n; i++) {
            if(visited[i] == 0) {
                dfs(i, visited, adj, st, cycle);
                if(cycle == true) {
                    return {};
                }
            }
        }

        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = toptSort(rowConditions, k);
        vector<int> topoCol = toptSort(colConditions, k);

        if(topoRow.empty() || topoCol.empty()) {
            return {};  // found cycl --> ans not possible
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(topoRow[i] == topoCol[j]) {
                    matrix[i][j] = topoRow[i];  // topoCol[j]
                }
            }
        }

        return matrix;
    }
};