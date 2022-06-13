class Solution {
public:
    bool solve(vector<int>& nums,int range,int target){
        int n = nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(range+1,false));
        for(int i=0;i<n+1;i++) dp[i][0] = true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<range+1;j++){
                if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),sum=0,target;
        for(auto& i:nums) sum+=i;
        if(sum%2!=0) return false;
        target = sum/2;
        return solve(nums,sum,target);
    }
};