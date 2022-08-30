class Solution {
public:
    
    bool check(vector<int>&nums, int thr, int div){
        int sum = 0;
        for(auto& i:nums){
            sum+=ceil((float)i/div);
        }
        return sum<=thr;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), l = 1, h = *max_element(nums.begin(),nums.end()),divisor,res;
        
        while(l<=h){
            divisor = l+(h-l)/2;
            if(check(nums,threshold,divisor)){
                res = divisor;
                h = divisor - 1;
            }
            else l = divisor + 1;
        }
        
        return res;
    }
};