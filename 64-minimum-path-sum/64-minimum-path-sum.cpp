class Solution {
private:
    int t[201][201];
public:
    int solve(vector<vector<int>>& grid,int i, int j){
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(t[i][j]!=-1) return t[i][j];
        else if(i==grid.size()-1) return t[i][j]=grid[i][j]+solve(grid,i,j+1);
        else if(j==grid[0].size()-1) return t[i][j]=grid[i][j]+solve(grid,i+1,j);
        return t[i][j]=grid[i][j]+min(solve(grid,i+1,j),solve(grid,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(grid,0,0);
    }
};