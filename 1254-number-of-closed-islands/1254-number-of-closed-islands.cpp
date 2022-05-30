class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i, int j){
        if(i<0 || i>=grid.size() || j>=grid[0].size() || j<0) return false;
        if(grid[i][j]==1) return true;
        grid[i][j] = 1;
        bool l,r,t,d;
        t = dfs(grid,i-1,j);
        d = dfs(grid,i+1,j);
        l = dfs(grid,i,j-1);
        r = dfs(grid,i,j+1);
        
        return t&&d&&l&&r;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)) res++;
                }
            }
        }
        return res;
    }
};