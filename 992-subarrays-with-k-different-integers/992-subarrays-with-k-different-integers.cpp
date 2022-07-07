class Solution {
public:
    int helper(vector<int>& nums,int k){
        int n = nums.size(),j=0,res=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            while(j<n && m.size()>k){
                m[nums[j]]--;
                if(m[nums[j]]==0) m.erase(nums[j]);
                j++;
            }
            res+=(i-j+1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};