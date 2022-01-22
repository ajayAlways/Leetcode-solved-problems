class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,total=0;
        queue<pair<int,int> >q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0) total++; 
            }
        }
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        
        while(!q.empty()){
            int size = q.size();
            total-=size;
            for(int i=0;i<size;i++){
                int r = q.front().first,c=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nr = r+dx[j],nc = c+dy[j];
                    if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size() || grid[nr][nc]!=1) continue;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
            if(!q.empty()) count++;
        }
        return total==0 ? count:-1;
    }
};