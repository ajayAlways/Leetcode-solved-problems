class Solution {
// private:
//     bool t[10001];
public:
    // bool solve(vector<int>& nums, int n, int i){
    //     //BC
    //     if(i>=n) return true;
    //     if(t[i]==true) return true;
    //     int reach = i+nums[i];
    //     for(int k=i+1;k<=reach;k++){
    //         if(solve(nums,n,k)) return t[i] = true;
    //     }
    //     return t[i]=false;
    // }
    bool canJump(vector<int>& nums) {
        // memset(t,false,sizeof(t));
        // return solve(nums,nums.size()-1,0);
        int minjump=0;
        for(int i=nums.size()-2;i>=0;i--){
            minjump++;
            if(nums[i]>=minjump) minjump = 0;
            
        }
        return minjump==0;
    }
};