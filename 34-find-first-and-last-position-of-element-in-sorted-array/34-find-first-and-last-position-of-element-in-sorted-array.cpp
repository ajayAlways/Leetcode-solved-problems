class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1, mid,start=-1,end=-1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]==target){
                start = mid;
                h = mid-1;
            }
            else if(nums[mid]<target) l = mid+1;
            else h = mid - 1;
        }
        l = 0, h = nums.size()-1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(nums[mid]==target){
                end = mid;
                l = mid+1;
            }
            else if(nums[mid]<target) l = mid+1;
            else h = mid - 1;
        }
        return {start,end};
    }
};