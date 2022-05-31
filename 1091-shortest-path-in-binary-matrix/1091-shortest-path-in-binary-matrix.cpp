class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& vis){
        int dx[8] = {0,1,1,1,0,-1,-1,-1};
        int dy[8] = {1,1,0,-1,-1,-1,0,1};
        int res=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                int r = q.front().first, c = q.front().second;
                q.pop();
                if(r== grid.size()-1 && c==grid[0].size()-1) return res;
                for(int k=0;k<8;k++){
                    int nr = r+dx[k], nc = c+dy[k];
                    if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==0 && vis[nr][nc]==0){
                        q.push({nr,nc});   
                        vis[nr][nc]=1;
                    }
                }
            }  
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res,m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        if(grid[0][0]==0 && grid[m-1][n-1]==0) res = bfs(grid,0,0,vis);
        else return -1;
        return res;
    }
};