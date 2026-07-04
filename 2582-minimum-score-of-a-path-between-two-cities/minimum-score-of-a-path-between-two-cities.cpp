class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int dis = it[2];

            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }

        int mini = INT_MAX;
        queue<int> q;

        q.push(1);
        vector<bool> vis(n + 1, 0);
        vis[1] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto node : adj[u]) {
                int next_node = node.first;
                int dis_to = node.second;

                mini = min(mini, dis_to);
                if (!vis[next_node]) {
                    vis[next_node] = 1;
                    q.push(next_node);
                }
            }
        }

        return mini;
    }
};