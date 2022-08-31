class Solution {
public:
    
    void dfs(vector<vector<int>>&h,int i, int j, vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=h.size() || j>=h[0].size() || vis[i][j]==1) return;
        
        vis[i][j] = 1;
        
        if(i+1<h.size() && h[i][j]<=h[i+1][j]) dfs(h,i+1,j,vis);
        if(j+1<h[0].size() && h[i][j]<=h[i][j+1]) dfs(h,i,j+1,vis);
        if(i>0 && h[i][j]<=h[i-1][j]) dfs(h,i-1,j,vis);
        if(j>0 && h[i][j]<=h[i][j-1]) dfs(h,i,j-1,vis);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        vector<vector<int>>res;
        
        for(int i=0;i<m;i++) dfs(h,i,0,pacific), dfs(h,i,n-1,atlantic);
        for(int i=0;i<n;i++) dfs(h,0,i,pacific), dfs(h,m-1,i,atlantic);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1) res.push_back({i,j});
            }
        }
        
        return res;
    }
};