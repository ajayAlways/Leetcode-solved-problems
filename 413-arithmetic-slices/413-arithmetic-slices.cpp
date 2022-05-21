class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int j=0,diff=nums[0]-nums[1],ans=0;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                int l = i-j+1;
                if(l>=3) ans+=((l-2)*(l-1)/2);
            }
            else if(diff!=nums[i]-nums[i+1]){
                int l = i-j+1;
                if(l>=3) ans+=((l-2)*(l-1)/2);
                j=i;
                diff = nums[i]-nums[i+1];
            }
        }
        return ans;
    }
};