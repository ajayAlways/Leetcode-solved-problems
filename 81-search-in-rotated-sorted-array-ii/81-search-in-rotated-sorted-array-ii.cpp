class Solution {
public:
    int binarySearch(int i, int j,vector<int>nums,int target){
        int l=i,h=j,mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int lo =0, hi = nums.size()-1;
        int mid = 0;
        while(lo<hi){
              mid=(lo+hi)/2;
              if(nums[mid]==target) return true;
              if(nums[mid]>nums[hi]){
                  if(nums[mid]>target && nums[lo] <= target) hi = mid;
                  else lo = mid + 1;
              }else if(nums[mid] < nums[hi]){
                  if(nums[mid]<target && nums[hi] >= target) lo = mid + 1;
                  else hi = mid;
              }else{
                  hi--;
              }

        }
    return nums[lo] == target ? true : false;
    }
};