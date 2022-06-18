class Solution {
private:
    int dp[1001][1001];
public:
    void LCS(string& x, string& y){
        memset(dp,0,sizeof dp);
        int m = x.length(), n = y.length();
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(x[i-1]==y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int i=str1.length(),j=str2.length();
        LCS(str1,str2);
        string res="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                res+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    res+=str1[i-1];
                    i--;
                }
                else{
                    res+=str2[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            res+=str1[i-1];
            i--;
        }
        while(j>0){
            res+=str2[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};