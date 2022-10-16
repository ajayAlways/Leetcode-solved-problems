class Solution {
public:
    
//     int solve(vector<int>&jd, int i, int d, int maxEle,vector<vector<int>>&memo){
//         if(d==1) return *max_element(jd.begin()+i,jd.end());
//         if(i>=jd.size()-1) return (int)(1e9);
        
//         if(memo[i][d]!=-1) return memo[i][d];
        
//         if(maxEle==-1 || jd[maxEle]<=jd[i]) maxEle = i;
//         int cut = jd[maxEle] + solve(jd,i+1,d-1,-1,memo);
//         int noCut = solve(jd,i+1,d,maxEle,memo);
        
//         return memo[i][d] = min(cut,noCut);
//     }
    
    int minDifficulty(vector<int>& A, int D) {
        // if(d>jobDifficulty.size()) return -1;
        // int n = jobDifficulty.size();
        // vector<vector<int>>memo(n,vector<int>(n,vector<int>));
        // return solve(jobDifficulty,0,d,-1,memo);
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};