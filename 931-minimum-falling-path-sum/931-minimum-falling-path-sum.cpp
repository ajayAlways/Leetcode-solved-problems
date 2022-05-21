class Solution {

public:
//     int solve(vector<vector<int>>& matrix, int i, int j){
//         if(j<0 || j>matrix.size()-1) return INT_MAX;
//         if(i==0) return t[i][j]=matrix[i][j];
        
//         if(t[i][j]!=INT_MAX) return t[i][j];
        
//         int dl,dr,d;
        
//         dl = solve(matrix,i-1,j-1);
//         d = solve(matrix,i-1,j);
//         dr = solve(matrix,i-1,j+1);
        
//         return t[i][j] = min(min(dl,dr),d)+matrix[i][j];
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX,n=matrix.size();
        int dp[101][101];
        for(int i=0;i<n;i++) dp[0][i] = matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j],ul=matrix[i][j],ur=matrix[i][j];
                if(j<=0) ul=INT_MAX;
                else ul+=dp[i-1][j-1];
                if(j>=matrix[0].size()-1) ur=INT_MAX;
                else ur+=dp[i-1][j+1];
                
                dp[i][j] = min(min(ur,ul),up);
            }
        }
        for(int i=0;i<matrix.size();i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
        // for(int i=0;i<matrix.size();i++){
        //     ans = min(ans,solve(matrix,matrix.size()-1,i));
        // }
        // return ans;
    }
};