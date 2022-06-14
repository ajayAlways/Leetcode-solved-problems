class Solution {
public:
    int LCS(string x, string y){
        int m = x.length(), n = y.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(x[i-1]==y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length(), lcs;
        lcs = LCS(word1, word2);
        return m+n - 2*lcs;
    }
};