class Solution {
public:
    void dfsearch(int node, vector<bool>& vis, vector<int>& ans,
                  vector<vector<int>>& adj) {
        vis[node] = 1;
        ans.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsearch(it, vis, ans, adj);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();

        vector<bool> vis(n, 0);

        vector<int> ans;

        dfsearch(0, vis, ans, adj);

        return ans;
    }
};