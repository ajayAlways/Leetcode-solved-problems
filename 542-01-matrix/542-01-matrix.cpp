class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dx[i],nc=c+dy[i];
                if(nr>=0 && nc>=0 && nr<mat.size() && nc<mat[0].size()){
                    if(ans[nr][nc]>ans[r][c]+1){
                        ans[nr][nc] = ans[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return ans;
    }
};