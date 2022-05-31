class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;
        
        grid[i][j] = 2;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=  grid.size(), n = grid[0].size(),flag=1,res=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(flag){
                        dfs(grid, i, j);
                        flag = 0;
                    }
                    else q.push({i,j});
                }
            }
        }
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        vector<vector<int>>vis(m,vector<int>(n,0));
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                int r = q.front().first, c = q.front().second;
                q.pop();
                vis[r][c] = 1;
                for(int j=0;j<4;j++){
                    int nr = r+dx[j],nc = c+dy[j];
                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && vis[nr][nc]==0){
                        if(grid[nr][nc]==0){
                            q.push({nr,nc});
                            vis[nr][nc] = 1;
                        }
                        if(grid[nr][nc]==2) return res-1;
                    }
                }
            }
        }
        return res-1;
    }
};