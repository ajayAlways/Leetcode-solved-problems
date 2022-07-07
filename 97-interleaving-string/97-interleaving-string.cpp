class Solution {
private:
    int dp[101][101];
public:
    bool solve(string s1, string s2,string s3,int idx1,int idx2,int n1,int n2,int n3){
        if(idx1+idx2==n3) return true;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(idx1<n1 && s1[idx1]==s3[idx1+idx2] && solve(s1,s2,s3,idx1+1,idx2,n1,n2,n3)) return dp[idx1][idx2] = true;
        if(idx2<n2 && s2[idx2]==s3[idx1+idx2] && solve(s1,s2,s3,idx1,idx2+1,n1,n2,n3)) return dp[idx1][idx2] = true;
        return dp[idx1][idx2] = false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int count = 0,change=0,n1=s1.length(), n2 = s2.length(), n3 = s3.length(),idx1=0,idx2=0;
        
        if(n1+n2!=n3) return false;
        memset(dp,-1,sizeof dp);
        return solve(s1,s2,s3,0,0,n1,n2,n3);
    }
};