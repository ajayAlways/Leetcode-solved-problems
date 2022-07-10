class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,0);
        int prev2 = cost[0];
        int prev1 = cost[1];
        for(int i=2;i<cost.size();i++){
            int temp = prev1;
            prev1 = cost[i] + min(prev1,prev2);
            prev2 = temp;
        }
        return min(prev1,prev2);
    }
};