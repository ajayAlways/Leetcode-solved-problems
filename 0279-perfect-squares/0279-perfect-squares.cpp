class Solution {
public:
    int numSquares(int n) {
        // coin change version  O(n^2)- time O(n^2)-space
        // vector<int>nums;
        // int num = sqrt(n),amount=n;
        // for(int i=1;i<=num;i++){
        //     nums.push_back(i*i);
        // }
        // n = nums.size();
        // int dp[n+1][amount+1];
        // for(int i=0;i<amount+1;i++) dp[0][i] = INT_MAX-1;
        // for(int i=0;i<n+1;i++) dp[i][0] = 0;
        // for(int i=1;i<amount+1;i++){
        //     if(i%nums[0]==0) dp[1][i] = i/nums[0];
        //     else dp[1][i] = INT_MAX-1;
        // }
        // for(int i=2;i<n+1;i++){
        //     for(int j=1;j<amount+1;j++){
        //         if(nums[i-1]<=j) dp[i][j] = min(1+dp[i][j-nums[i-1]],dp[i-1][j]);
        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[n][amount]!=INT_MAX-1 ? dp[n][amount]:-1;
        
        
        //  bfs 
        int res=0,target=n;
        n = sqrt(n);
        unordered_set<int>s;
        queue<int>q;
        q.push(0);
        s.insert(0);
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i=0;i<size;i++){
                int num = q.front();
                q.pop();
                for(int j=1;j<=n;j++){
                    if(num+j*j == target) return res;
                    if(!s.count(num+j*j)){
                        q.push(num+j*j);
                        s.insert(num+j*j);
                    }
                }
            }
        }
        return res;
    }
};