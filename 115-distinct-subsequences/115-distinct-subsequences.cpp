class Solution {
public:
    int memo[1001][1001];

    int solve(string x, string y, int i, int j){
        if(i>=x.length() && j>=y.length()) return 1;
        if(i>=x.length()) return 0;
        if(j>=x.length()) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        if(x[i]==y[j]){
            int temp1,temp2;
            if(memo[i+1][j+1]!=-1) temp1 = memo[i+1][j+1];
            else temp1 = solve(x,y,i+1,j+1);
            if(memo[i+1][j]!=-1) temp2 = memo[i+1][j];
            else temp2 = solve(x,y,i+1,j);
            return memo[i][j] = temp1 + temp2;
        }
        return memo[i][j] = solve(x,y,i+1,j);
    }
    
    int numDistinct(string s, string t) {
        if(s==t) return 1;
        memset(memo,-1,sizeof memo);
        return solve(s,t,0,0);
    }
};