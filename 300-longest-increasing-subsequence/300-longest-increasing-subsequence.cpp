class Solution {
public:
    
//     int solve(vector<int>& nums, int cur, int prev){
//         if(cur>=nums.size()) return 0;
//         if(memo[prev+1]!=-1) return memo[prev+1];
//         int take = 0,doNotTake = solve(nums,cur+1,prev);
//         if(prev==-1 || nums[cur]>nums[prev]){
//             take = 1+solve(nums,cur+1,cur);
//         }
        
//         return memo[prev+1] = max(take,doNotTake);
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),res=1;
        vector<int>dp(n,1);
        // return solve(nums,0,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],1+dp[j]), res = max(res,dp[i]);
            }
        }
        return res;
    }
};