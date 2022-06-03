class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis,vector<int>& dp){
        if(vis[node]) return false;
        if(adj[node].size()==0) return true;
        if(dp[node]!=-1) return dp[node];
        vis[node] = 1;
        bool ans = true;
        for(auto& i:adj[node]){
            if(!dfs(adj,i,vis,dp)) return ans=false;
        }
        vis[node] = 0;
        return dp[node] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0),res;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            if(dfs(graph,i,vis,dp)) res.push_back(i);
        }
        return res;
    }
};