class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int begin=0,end=nums.size()-1,j=nums.size()-1;
        vector<int>ans(nums.size(),0);
        while(begin<=end){
            if(abs(nums[begin])>=abs(nums[end])) ans[j--]=nums[begin]*nums[begin++];
            else ans[j--] = nums[end]*nums[end--];
        }
        return ans;
    }
};