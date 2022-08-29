class Solution {
public:
    
    int solve(vector<vector<int>>&grid, int x1, int y1, int x2,vector<vector<vector<int>>>&dp){
        int y2 = x1+y1-x2;
        if(x1>=grid.size() || y1>=grid[0].size() || x2>=grid.size() || y2>=grid[0].size() || grid[x1][y1]==-1 || grid[x2][y2]==-1) return INT_MIN;
        
        if(dp[x1][y1][x2]!=-1) return dp[x1][y1][x2];
        
        if(x1==grid.size()-1 && y1==x1) return grid[x1][y1];
        
        int cherries = 0;
        
        if(x1==x2 && y1==y2){
            cherries+=grid[x1][y1];
        }
        else{
            cherries+=grid[x1][y1] + grid[x2][y2];
        }
        
        int a = solve(grid,x1+1,y1,x2,dp);
        int b = solve(grid,x1+1,y1,x2+1,dp);
        int c = solve(grid,x1,y1+1,x2,dp);
        int d = solve(grid,x1,y1+1,x2+1,dp);
        
        return dp[x1][y1][x2] = max(max(a,b),max(c,d)) + cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        
        return max(solve(grid,0,0,0,dp),0);
    }
};