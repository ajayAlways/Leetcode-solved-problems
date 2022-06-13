class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis, int node){
        vis[node] = 1;
        for(int i=1;i<adj.size();i++){
            if(adj[node][i] && !vis[i]) dfs(adj,vis,i);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
                adj[edges[i][0]][edges[i][1]] = 1;
                adj[edges[i][1]][edges[i][0]] = 1;
            }
        for(int i=n-1;i>=0;i--){
            adj[edges[i][0]][edges[i][1]] = 0;
            adj[edges[i][1]][edges[i][0]] = 0;
            
            dfs(adj,vis,1);
            int count=0;
            for(auto& i:vis){
                if(i==1) count++;
                i=0;
            }
            if(count==n) return edges[i];
            adj[edges[i][0]][edges[i][1]] = 1;
            adj[edges[i][1]][edges[i][0]] = 1;
        }
        return {-1,-1};
    }
};