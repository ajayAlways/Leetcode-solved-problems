class Solution {
// private:
//     int t[1001][1001];
public:
    // int solve(string s1, string s2, int x, int y){
    //     if(x<0 || y<0) return 0;
    //     if(t[x][y]!=-1) return t[x][y];
    //     if(s1[x]==s2[y]) return t[x][y] = 1+solve(s1,s2,x-1,y-1);
    //     else return t[x][y] = max(solve(s1,s2,x-1,y),solve(s1,s2,x,y-1));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(t,-1,sizeof(t));
        // return solve(text1,text2,text1.length()-1,text2.length()-1);
        int dp[1001][1001];
        int m=text1.length(),n=text2.length();
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else if(text1[i-1]!=text2[j-1]) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};