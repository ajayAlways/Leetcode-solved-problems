class Solution {
public:
//     bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
//         if(i==0 && j==0) return true;
//         if(j==0 && i>0) return false;
//         if(i==0 && j>0){
//             for(int ii=0;ii<j;ii++){
//                 if(p[ii]!='*') return false;
//             }
//             return true;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
//         else if(p[j-1]=='*'){
//             return dp[i][j] = solve(s,p,i,j-1,dp) | solve(s,p,i-1,j,dp);
//         }
        
//         return dp[i][j] = false;
//     }
    
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i=1;i<n+1;i++) dp[i][0] = false;
        for(int j=1;j<m+1;j++){
            bool flag = true;
            for(int ii=0;ii<j;ii++){
                if(p[ii]!='*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};