class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(),maxi=INT_MIN;
        for(int i=0;i<n-2;i++){
            maxi = max(maxi,nums[i]);
            if(maxi>nums[i+2]) return false;
        }
        return true;
    }
};