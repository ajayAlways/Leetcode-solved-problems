class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        int leftProd=1,rightProd=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=leftProd;
            ans[nums.size()-i-1]*=rightProd;
            leftProd*=nums[i];
            rightProd*=nums[nums.size()-i-1];
        }
        return ans;
    }
};