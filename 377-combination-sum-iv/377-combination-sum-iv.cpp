class Solution {
private:
    int t[1001];
public:
    int solve(vector<int>& nums, int target){
        if(target<=0) return 1;
        if(t[target]!=-1) return t[target];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                res+=solve(nums,target-nums[i]);
            }
        }
        return t[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof t);
        return solve(nums,target);
        
    }
};