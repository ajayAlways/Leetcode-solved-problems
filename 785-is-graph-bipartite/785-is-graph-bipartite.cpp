class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node,vector<int>& vis,int color){
        vis[node] = color;
        for(auto& i:adj[node]){
            if(vis[i]!=-1 && vis[i]==color) return false;
            if(vis[i]==-1){
                if(!dfs(adj,i,vis,!color)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(graph,i,vis,0)) return false;
            }
        }
        return true;
    }
};