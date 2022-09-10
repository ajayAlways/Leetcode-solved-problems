class Solution {
public:
    
    int solve(vector<int>&prices, int i, int c, int k, bool buy, vector<vector<vector<int>>>&dp){
        
        if(i>=prices.size() || c>=k) return 0;
        
        if(dp[i][buy][c]!=-1) return dp[i][buy][c];
        
        
        if(buy){
            return dp[i][buy][c] = max(-prices[i] + solve(prices,i+1,c,k,!buy,dp) ,solve(prices,i+1,c,k,buy,dp));
            
        }
        else{
            return dp[i][buy][c] = max(prices[i] + solve(prices,i+1,c+1,k,!buy,dp),solve(prices, i+1,c, k, buy,dp));
        }
        
    }
    
    int maxProfit(vector<int>& prices, int k=2) {
        int n = prices.size(),res=0;
        if(2*k>=n){
            for(int i=1;i<n;i++){
                res+=max(0,prices[i]-prices[i-1]);
            }
            
            return res;
        }
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,0,k,1,dp);
    }
};