class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adj[u].push_back({v, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        adj[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> ans(N, INT_MAX); // shortest distance from source node1 to all other vertices

        ans[node1] = 0;
        pq.push({0, node1});

        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &vec : adj[node]) {
                int adjNode = vec.first;
                int dist = vec.second;

                if(d + dist < ans[adjNode]) {
                    ans[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }

        return ans[node2] == INT_MAX ? -1 : ans[node2];  // shortest distance from source node1 to node2
    }
};

