class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        int n = nums.size(),j=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            sum+=nums[i];
            while(j<i && m[nums[i]]>1){
                m[nums[j]]--;
                sum-=nums[j];
                j++;
            }
            res = max(res,sum);
        }
        
        return res;
    }
};