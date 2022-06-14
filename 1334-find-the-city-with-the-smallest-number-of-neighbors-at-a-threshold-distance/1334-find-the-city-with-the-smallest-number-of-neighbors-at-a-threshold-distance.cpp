class Solution {
public:
    // DFS does not work
    // void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& vis, int node, int limit){
    //     if(limit>=0) vis[node] = 1;
    //     if(limit<=0) return;
    //     for(auto& i:adj[node]){
    //         if(!vis[i.first]) dfs(adj,vis,i.first,limit-i.second);
    //     }    
    // }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mini = INT_MAX,res=0,INF = (int)1e6;
        vector<vector<int>>dist(n,vector<int>(n,INF));
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(auto& i:edges){
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        // Floyd Algorithm
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j]<=distanceThreshold) count++;
            }
            if(count<=mini){
                mini = count;
                res = i;
            }
        }
        return res;
    }
};