
void dfs(vector<vector<int>>& grid,int r,int c,int &count){
    if(grid[r][c]==1){
        count++;
        grid[r][c] = 0;
        if(r>=1) dfs(grid,r-1,c,count);
        if(c>=1) dfs(grid,r,c-1,count);
        if(r+1<grid.size()) dfs(grid,r+1,c,count);
        if(c+1<grid[0].size()) dfs(grid,r,c+1,count);
    }
    else return;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0,count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,count);
                    ans = max(count,ans);
                    count=0;
                }
            }
        }
        return ans;
    }
};