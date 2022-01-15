class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numberOfZeros = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) numberOfZeros++;
            else if(numberOfZeros>0){
                swap(nums[i],nums[i-numberOfZeros]);
            }
        }
    }
};