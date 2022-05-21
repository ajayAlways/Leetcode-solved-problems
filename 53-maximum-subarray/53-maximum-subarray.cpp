class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int sum=0,ans=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     ans = max(ans,sum);
        //     if(sum<0) sum=0;
        // }
        // return ans;
        int dp[nums.size()];
        dp[0]=nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = nums[i]+(dp[i-1]>0 ? dp[i-1]:0);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};