
void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int r,int c,int &count){
    if(grid[r][c]==1 && !visited[r][c]){
        count++;
        visited[r][c] = 1;
        if(r>=1) dfs(grid,visited,r-1,c,count);
        if(c>=1) dfs(grid,visited,r,c-1,count);
        if(r+1<grid.size()) dfs(grid,visited,r+1,c,count);
        if(c+1<grid[0].size()) dfs(grid,visited,r,c+1,count);
    }
    else return;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0,count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(grid,visited,i,j,count);
                    ans = max(count,ans);
                    count=0;
                }
            }
        }
        return ans;
    }
};