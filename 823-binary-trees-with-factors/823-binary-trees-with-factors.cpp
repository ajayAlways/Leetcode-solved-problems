class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(),mod=1e9+7;
        long long res=0;
        sort(arr.begin(),arr.end());
        vector<long>dp(n,1);
        unordered_map<int,int>m;
        for(int i=0;i<n;i++) m[arr[i]] = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(arr[i]%arr[j]==0){
                    if(m.find(arr[i]/arr[j])!=m.end()){
                        long left = dp[m[arr[j]]];
                        long right = dp[m[arr[i]/arr[j]]];
                        dp[i] = (dp[i]+left*right)%mod;
                    }
                }
            }
        }
        for(auto& i:dp){
            res = (res+i)%mod;
        }
        
        return res;
    }
};