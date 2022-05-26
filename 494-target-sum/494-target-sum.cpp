class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),range=0;
        for(auto& i:nums) range+=i;
        if((range+target)%2!=0 || range<abs(target)) return 0;
        target = (range+target)/2;
        int dp[n+1][range+1];
        for(int i=0;i<range+1;i++) dp[0][i] = 0;
        for(int j=0;j<n+1;j++) dp[j][0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<range+1;j++){
                if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};