class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node,vector<int>& vis){
        vis[node]=1;
        for(auto& i:adj[node]){
            if(!vis[i]) dfs(adj,i,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),res=0;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && isConnected[i][j]==1) adj[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                res++;
            }
        }
        return res;
    }
};