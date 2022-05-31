class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(),n = maze[0].size(),res=-1;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                int r = q.front().first, c = q.front().second;
                q.pop();
                if((r==0 || c==0 || r==m-1 || c==n-1) && (r!=entrance[0] || c!=entrance[1])) return res;
                for(int j=0;j<4;j++){
                    int nr = r + dx[j], nc = c + dy[j];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && maze[nr][nc]=='.'){
                        maze[nr][nc] = '+';
                        q.push({nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};