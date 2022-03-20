class Solution {
public:
    int t[10001];
    int solve(vector<int>&cost, int i){
        //base case
        if(i<0) return 0;
        if(i==0 || i==1) return cost[i];
        if(t[i]!=0) return t[i];
        return t[i] = cost[i] + min(solve(cost,i-1),solve(cost,i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(),res;
        res = min(solve(cost,n-1),solve(cost,n-2));
        return res;
    }
};