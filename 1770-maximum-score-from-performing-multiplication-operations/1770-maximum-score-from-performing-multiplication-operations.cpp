class Solution {
public:
    
    int solve(vector<int>&nums, vector<int>&mul, int i,int k, vector<vector<int>>&dp){
        if(k>=mul.size()) return 0;
        
        int j = nums.size() - (k-i) - 1;
        
        if(dp[k][i]!=int(1e9)) return dp[k][i];
        
        int l = mul[k]*nums[i] + solve(nums,mul,i+1,k+1,dp);
        int r = mul[k]*nums[j] + solve(nums,mul,i,k+1,dp);
        
        return dp[k][i] = max(l,r);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        vector<vector<int>>dp(mul.size()+1,vector<int>(mul.size()+1,int(1e9)));
        
        return solve(nums,mul,0,0,dp);
    }
};