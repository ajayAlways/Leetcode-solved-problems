class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& visited,int i, int j){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || visited[i][j]==1) return;
        visited[i][j] = 1;
        if(i+1<heights.size() && heights[i][j]<=heights[i+1][j]) dfs(heights,visited,i+1,j);
        if(i>0 && heights[i][j]<=heights[i-1][j]) dfs(heights,visited,i-1,j);
        if(j+1<heights[0].size() && heights[i][j]<=heights[i][j+1]) dfs(heights,visited,i,j+1);
        if(j>0 && heights[i][j]<=heights[i][j-1]) dfs(heights,visited,i,j-1);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>ans;
        for(int i=0;i<m;i++) dfs(heights,pacific,i,0),dfs(heights,atlantic,i,n-1);
        for(int i=0;i<n;i++) dfs(heights,pacific,0,i),dfs(heights,atlantic,m-1,i);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};