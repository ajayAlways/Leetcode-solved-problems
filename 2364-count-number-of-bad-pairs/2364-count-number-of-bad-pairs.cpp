class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            res+=i-m[nums[i]-i];
            m[nums[i]-i]++;
        }
        
        return res;
    }
};