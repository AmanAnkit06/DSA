class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V,0);
        vector<vector<int>>adj(V);
        for(auto it:edges){
            int v=it[0];
            int u=it[1];
            adj[v].push_back(u);
            indegree[u]++;
            
        }
      
        
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};