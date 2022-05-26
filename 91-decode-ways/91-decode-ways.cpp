class Solution {
private:
    int t[101];
public:
    int solve(string& s,int n){
        //BC         
        if(n==s.length()) return 1;
        if(s[n]=='0') return 0;
        
        if(t[n]!=-1) return t[n];
        // Hypothesis
        t[n] = solve(s,n+1);
        if(n<s.length()-1 && (s[n]=='1' || (s[n]=='2' && s[n+1]<'7'))) t[n]+=solve(s,n+2);
        
        return t[n];
    }
    int numDecodings(string s) {
        memset(t,-1,sizeof t);
        return solve(s,0);
    }
};