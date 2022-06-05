class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size(),res=0,start=0,next=0;
        sort(nums.begin(),nums.end());
        
        while(start<n){
            while(next<n && nums[next]-nums[start]<=k ) next++;
            start = next;
            res++;
        }
        return res;
    }
};