class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(),res=0,middle = n/2;
        sort(nums.begin(),nums.end());
        for(auto& i:nums){
            res+=abs(i-nums[middle]);
        }
        
        return res;
    }
};