class Solution {
private:
    int memo[2501];
    
public:
    
    int solve(vector<int>& nums, int cur, int prev){
        if(cur>=nums.size()) return 0;
        if(memo[prev+1]!=-1) return memo[prev+1];
        int take = 0,doNotTake = solve(nums,cur+1,prev);
        if(prev==-1 || nums[cur]>nums[prev]){
            take = 1+solve(nums,cur+1,cur);
        }
        
        return memo[prev+1] = max(take,doNotTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(memo,-1,sizeof memo);
        return solve(nums,0,-1);
    }
};