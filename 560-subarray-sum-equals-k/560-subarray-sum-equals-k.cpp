class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,count=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[sum]++;
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()) count+=m[sum-k];
        }
        return count;
    }
};