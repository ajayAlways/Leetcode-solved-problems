class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        vector<vector<int>>adj(n,vector<int>(n,0));
        int res=0;
        for(auto& i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
            adj[i[0]][i[1]] = 1;
            adj[i[1]][i[0]] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!adj[i][j] || !adj[j][i]) res = max(res,degree[i]+degree[j]);
                else res = max(res,degree[i]+degree[j]-1);
            }
        }
        return res;
    }
};