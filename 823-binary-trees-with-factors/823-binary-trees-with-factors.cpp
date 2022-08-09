class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(),mod=1e9+7;
        long long res=0;
        sort(arr.begin(),arr.end());
        unordered_map<int,long>dp;
        for(int i=0;i<n;i++) dp[arr[i]] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(dp.find(arr[i]/arr[j])!=dp.end()){
                        long left = dp[arr[j]];
                        long right = dp[arr[i]/arr[j]];
                        dp[arr[i]] = (dp[arr[i]]+left*right)%mod;
                    }
                }
            }
        }
        for(auto& i:dp){
            res = (res+i.second)%mod;
        }
        
        return res;
    }
};