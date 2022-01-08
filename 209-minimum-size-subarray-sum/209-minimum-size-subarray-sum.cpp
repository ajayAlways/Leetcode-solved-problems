class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0,ans=INT_MAX,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
            
        }
        return ans!=INT_MAX?ans:0;
    }
};