class Solution {
private:
    int memo[101][101][21];
public:
    int dfs(vector<int>& houses, vector<vector<int>>& cost,int m, int n,int nb, int target, int i,int prev){
        if(i==m) return nb==target ? 0:1000001;
        if(nb>target) return 1000001;
        
        if(memo[i][nb][prev]!=-1) return memo[i][nb][prev];
        
        int minCost = 1000001;
        
        if(houses[i]!=0){
            int newNb = nb+(houses[i]!=prev);
            minCost = dfs(houses,cost,m,n,newNb,target,i+1,houses[i]);
        }
        
        else{
            for(int j=0;j<n;j++){
                int newNb = nb+((j+1)!=prev);
                int curCost = cost[i][j] + dfs(houses,cost,m,n,newNb,target,i+1,j+1);
                minCost = min(minCost,curCost);
            }
        }
        return memo[i][nb][prev] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo,-1,sizeof memo);
        int res = dfs(houses,cost,m,n,0,target,0,0);
        return res!=1000001 ? res:-1;
    }
};