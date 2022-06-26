class Solution {
private:
    int dp[201][201];
public:
    int dfs(vector<vector<int>>& matrix, int x, int y,int prev){
        if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size() || prev>=matrix[x][y]) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int l = 1 + dfs(matrix,x-1,y,matrix[x][y]);
        int u = 1 + dfs(matrix,x,y-1,matrix[x][y]);
        int r = 1 + dfs(matrix,x+1,y,matrix[x][y]);
        int d = 1 + dfs(matrix,x,y+1,matrix[x][y]);
        
        return dp[x][y] = max(l,max(u,max(r,d)));
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        int res=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res = max(res,dfs(matrix,i,j,-1));
            }
        }
        
        return res;
    }
};