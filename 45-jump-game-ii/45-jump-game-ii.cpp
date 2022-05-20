class Solution {
public:
    // int solve(vector<int>& nums, int i, int n){
    //     if(i>=n) return 0;
    //     int reach = i+nums[i];
    //     int minJumps = n;
    //     for(int k=reach;k>i;k--){
    //         minJumps = min(minJumps,1+solve(nums,k,n));
    //     }
    //     return minJumps;
    // }
    int jump(vector<int>& nums) {
        // return solve(nums,0,nums.size()-1);
        if(nums.size()<2) return 0;
        int maxjump= nums[0],curjump = nums[0],i=0,jumps=1;
        while(i<nums.size()-1){
            maxjump = max(maxjump,i+nums[i]);
            if(i==curjump){
                jumps++;
                curjump=maxjump;
            }
            i++;
        }
        return jumps;
    }
};