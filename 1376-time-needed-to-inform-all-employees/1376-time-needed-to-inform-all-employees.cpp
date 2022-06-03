class Solution {
    
public:
    int dfs(vector<vector<int>>& adj, vector<int>& time, int node){
        if(adj[node].size()==0) return time[node];
        int res = 0;
        for(auto& i:adj[node]){
             res = max(res,time[node] + dfs(adj,time,i));
        }
        return res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        return dfs(adj,informTime,headID);
    }
};