class Solution {
public:
    int t[10001];
    int solve(vector<int>&cost,int n){
        for(int i=0;i<n;i++){
            if(i<2) t[i] = cost[i];
            else t[i] = cost[i] + min(t[i-1],t[i-2]);
        }
        return min(t[n-1],t[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(),res;
        res = solve(cost,n);
        return res;
    }
};