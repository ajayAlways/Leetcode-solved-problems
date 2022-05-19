class Solution {

public:
    int solve(vector<int>nums){
        vector<int>dp(10001,0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i=2;i<nums.size();i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>v(10001,0);
        for(auto& i:nums){
            v[i]+=i;
        }
        return solve(v);
    }
};