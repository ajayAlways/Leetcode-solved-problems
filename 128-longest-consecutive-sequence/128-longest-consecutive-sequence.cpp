class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(),res=0,cnt=1;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            if(i<n-1 && nums[i]+1==nums[i+1]) cnt++;
            else{
                res = max(res,cnt);
                cnt=1;
            }
        }
        
        return max(res,cnt);
    }
};