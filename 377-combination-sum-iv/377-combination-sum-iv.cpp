class Solution {
private:
    int memo[1001];
public:
    
    // int solve(vector<int>&nums,int target, int sum){
    //     if(sum==target){
    //         return 1;
    //     }
    //     if(memo[sum]!=-1) return memo[sum];
    //     int res=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(sum+nums[i]<=target) res+=solve(nums,target,sum+nums[i]);
    //     }
    //     return memo[sum] = res;
    // }
    
    int combinationSum4(vector<int>& nums, int target) {
        // int res=0;
        // memset(memo,-1,sizeof memo);
        // res = solve(nums,target,0);
        int n = nums.size();
        vector<unsigned int>dp(target+1,0);
        sort(nums.begin(),nums.end());
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(auto& num:nums){
                if(num>i) break;
                dp[i]+=dp[i-num];
            }
        }
        
        return dp[target];
    }
};