class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node,vector<int>& vis){
        vis[node]=1;
        for(auto& i:adj[node]){
            if(!vis[i]) dfs(adj,i,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        int res=0;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto& i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                res++;
            }
        }
        return res-1;
    }
};