class Solution {
public:
    int nthUglyNumber(int n) {
        int j2=0,j3=0,j5=0,count=1,res=1;
        if(n==1) return 1;
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i] = min(dp[j2]*2,min(dp[j3]*3,dp[j5]*5));
            if(dp[i]==dp[j2]*2) j2++;
            if(dp[i]==dp[j3]*3) j3++;
            if(dp[i]==dp[j5]*5) j5++;
        }
        return dp[n-1];
    }
};