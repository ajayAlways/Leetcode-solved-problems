class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),res=0;
        int dp=0;
        if(n<=2) return res;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) dp=1+dp;
            else dp = 0;
            res+=dp;
        }
        return res;
        
    }
};