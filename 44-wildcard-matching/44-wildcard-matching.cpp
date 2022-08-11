class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int ii=0;ii<=j;ii++){
                if(p[ii]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
        else if(p[j]=='*'){
            return dp[i][j] = solve(s,p,i,j-1,dp) | solve(s,p,i-1,j,dp);
        }
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};