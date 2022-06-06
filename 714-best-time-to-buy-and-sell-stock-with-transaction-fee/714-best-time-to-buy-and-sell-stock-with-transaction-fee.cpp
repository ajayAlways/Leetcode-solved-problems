class Solution {
private:
    int dp[50001][2];
public:
    int solve(vector<int>& prices,int i,bool buying,int& fee){
        if(i>=prices.size()) return 0;
        if(dp[i][buying]!=-1) return dp[i][buying];
        
        int cooldown = solve(prices,i+1,buying,fee);
        int res = 0;
        if(buying){
            int buy = solve(prices,i+1,!buying,fee)-prices[i]-fee;
            res = max(buy,cooldown);
        }
        else{
            int sell = solve(prices,i+1,!buying,fee)+prices[i];
            res = max(sell,cooldown);
        }
        return dp[i][buying] = res;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,true,fee);
    }
};