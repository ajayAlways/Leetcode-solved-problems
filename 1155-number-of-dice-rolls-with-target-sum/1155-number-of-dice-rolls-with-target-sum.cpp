class Solution {
public:
    
//     int solve(int n, int k, int target,vector<vector<long long>>&dp){
//         if(n==0 && target==0) return 1;
//         if(n<=0 || target<=0) return 0;
        
//         int mod = 1e9 + 7;
        
//         if(dp[n][target]!=-1) return dp[n][target]%mod;
            
//         long long res = 0;
        
//         for(int i=1;i<=k;i++){
//             if(target-i>=0) res = (res + long(solve(n-1,k,target-i,dp))%mod)%mod;
//         }
        
//         return dp[n][target] = res%mod;
        
//     }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int mod = 1e9 + 7;
                for(int l=1;l<=k;l++){
                    if(j-l>=0) dp[i][j] = (dp[i][j] + long(dp[i-1][j-l])%mod)%mod;
                }
            }
        }
        return dp[n][target];
    }
};