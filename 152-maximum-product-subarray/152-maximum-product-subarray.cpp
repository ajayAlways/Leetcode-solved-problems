class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax=1,curMin=1,res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                curMax=1;
                curMin=1;
            }
            int temp = curMax*nums[i];
            curMax = max(curMax*nums[i],max(curMin*nums[i],nums[i]));
            curMin = min(curMin*nums[i],min(temp,nums[i]));
            res = max(res,max(curMax,curMin));
        }
        return res;
    }
};