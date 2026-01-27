class Solution {
public:
    int dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int u = top.second;

            if (cost > dist[u])
                continue;
            if (u == n - 1) {
                return cost;
            }

            for (auto& p : adj[u]) {
                int v = p.first;
                int node_cost = p.second;

                if (dist[u] + node_cost < dist[v]) {
                    dist[v] = dist[u] + node_cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v, cost});

            adj[v].push_back({u, 2 * cost});
        }

        return dijkstra(n, adj, 0);
    }
};