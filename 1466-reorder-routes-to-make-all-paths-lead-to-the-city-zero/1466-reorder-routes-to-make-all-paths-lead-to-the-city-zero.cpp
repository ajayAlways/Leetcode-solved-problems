class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<vector<int>>& out,vector<int>& vis, int node,int parent, int& res){
        vis[node] = 1;
        if(parent!=-1){
            if(find(out[node].begin(),out[node].end(),parent)==out[node].end()) res++;
        }
        for(auto& i:adj[node]){
            if(!vis[i]) dfs(adj,out,vis,i,node,res);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int res=0;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        vector<vector<int>>out(n);
        for(auto& i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            out[i[0]].push_back(i[1]);
        }
        dfs(adj,out,vis,0,-1,res);
        return res;
    }
};