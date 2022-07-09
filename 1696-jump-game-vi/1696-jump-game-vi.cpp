class Solution {
public:
//     int findMaxScore(vector<int>& nums,vector<int>& memo, int k,int i){
//         if(memo[i]!=INT_MIN) return memo[i];
//         for(int j=i+1;j<=(i+k);j++){
//             if(j<nums.size())
//                 memo[i] = max(memo[i],nums[i]+findMaxScore(nums,memo,k,j));
//         }
        
//         return memo[i];
//     }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        multiset<int>st;
        dp[0] = nums[0];
        st.insert(dp[0]);
        for(int i=1;i<n;i++){
            if(i>k){
                st.erase(st.find(dp[i-k-1]));
            }
            dp[i] = *rbegin(st) + nums[i];
            st.insert(dp[i]);
        }
        return dp[n-1];
    }
};