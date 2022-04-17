class Solution {
public:
    int t[1001];
    int solve(vector<int>nums, int i, int j){
        if(i<j) return 0;
        if(t[i]!=-1) return t[i];
        return t[i] = max(nums[i]+solve(nums,i-2,j),solve(nums,i-1,j));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(t,-1,sizeof(t));
        int res1,res2;
        res1 = solve(nums, nums.size()-1,1);
        memset(t,-1,sizeof(t));
        res2 = solve(nums, nums.size()-2,0);
        return max(res1,res2);
    }
};