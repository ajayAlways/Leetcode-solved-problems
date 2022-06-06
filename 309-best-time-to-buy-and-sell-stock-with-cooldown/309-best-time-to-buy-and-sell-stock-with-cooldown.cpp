class Solution {
private:
    int dp[5001][2];
public:
    int solve(vector<int>& prices,int i,bool buying){
        if(i>=prices.size()) return 0;
        if(dp[i][buying]!=-1) return dp[i][buying];
        
        int cooldown = solve(prices,i+1,buying);
        int res = 0;
        if(buying){
            int buy = solve(prices,i+1,!buying)-prices[i];
            res = max(buy,cooldown);
        }
        else{
            int sell = solve(prices,i+2,!buying)+prices[i];
            res = max(sell,cooldown);
        }
        return dp[i][buying] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,true);
    }
};