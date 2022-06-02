class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node,vector<int>& vis){
        vis[node]=1;
        for(int i=0;i<adj.size();i++){
            if(node!=i && adj[node][i] && !vis[i]) dfs(adj,i,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),res=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,i,vis);
                res++;
            }
        }
        return res;
    }
};