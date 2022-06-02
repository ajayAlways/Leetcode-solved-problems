class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<bool>&check){
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size() || grid2[i][j]==0) return;
        
        grid2[i][j] = 0;
        
        if(grid1[i][j]==0) check[0] = false;
        
        dfs(grid1,grid2,i+1,j,check);
        dfs(grid1,grid2,i-1,j,check);
        dfs(grid1,grid2,i,j+1,check);
        dfs(grid1,grid2,i,j-1,check);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size(),res=0;
        vector<bool>check;
        check.push_back(true);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,check);
                    if(check[0]){
                        res++;
                    }
                    check[0] = true;
                }
            }
        }
        return res;
    }
};