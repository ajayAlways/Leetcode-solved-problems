class Solution {
public:
    int count_num(vector<int>& nums, int x){
        int count=0;
        for(auto& num:nums){
            if(num<=x) count++;
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1,l=1,h=n,mid,ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(count_num(nums,mid)>mid){
                ans = mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};