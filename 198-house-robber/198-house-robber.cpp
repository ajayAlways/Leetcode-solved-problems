class Solution {
public:
    int t[101];
    int solve(vector<int>nums, int n){
        if(n<0) return 0;
        if(t[n]!=-1) return t[n];
        return t[n] = max(nums[n]+solve(nums,n-2),solve(nums,n-1));
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int res = solve(nums,nums.size()-1);
        return res;
    }
};