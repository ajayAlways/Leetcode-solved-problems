class Solution {
private:
    int memo[2001];
public:
    bool isPalin(string &s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j){
        if(i>=j || isPalin(s,i,j)) return 0;
        if(memo[i]!=-1) return memo[i];
        int res = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(isPalin(s,i,k)){
                int temp = solve(s,k+1,j)+1;
                res = min(res,temp);
            }
            if(res==0) break;
        }
        
        return memo[i] = res;
    }
    
    int minCut(string s) {
        memset(memo,-1,sizeof memo);
        return solve(s,0,s.length()-1);
    }
};