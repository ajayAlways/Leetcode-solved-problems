class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) return false;
        long long prefixSum=0;
        unordered_map<long long,int>m;
        m[0] = -1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            if(m.find(prefixSum%k)!=m.end()){
                if(i-m[prefixSum%k]>=2) return true;
            }
            else m[prefixSum%k] = i;
        }
        
        return false;
    }
};