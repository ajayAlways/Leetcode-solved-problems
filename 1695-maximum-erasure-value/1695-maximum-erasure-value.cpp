class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum=0,j=0,n=nums.size(),res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            m[nums[i]]++;
            if(m[nums[i]]==1) res=max(res,sum);
            while(m[nums[i]]>1){
                sum-=nums[j];
                m[nums[j]]--;
                j++;
            }
        }
        return res;
    }
};