class Solution {
private:
    int memo[51][51][51];
public:
    int dfs(int m, int n, int maxMove, int move,int row, int column){
        if(move>maxMove) return 0;
        if(row<0 || column<0 || row>=m || column>=n){
            
            if(move<=maxMove) return 1;
            return 0;
        }
        if(memo[row][column][move]!=-1) return memo[row][column][move];
        int mod = 1e9 + 7;
        return memo[row][column][move] = ((dfs(m,n,maxMove,move+1,row,column-1)*1LL)%mod + (dfs(m,n,maxMove,move+1,row+1,column)*1LL)%mod +
            (dfs(m,n,maxMove,move+1,row,column+1)*1LL)%mod + (dfs(m,n,maxMove,move+1,row-1,column)*1LL)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1e9 + 7;
        memset(memo,-1,sizeof memo);
        return dfs(m,n,maxMove,0,startRow,startColumn)%mod;
    }
};