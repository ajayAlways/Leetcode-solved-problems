class Solution {
public:
    // bool isPalin(string s){
    //     int i=0,j=s.length()-1;
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    
    int countSubstrings(string s) {
        int n = s.length(),res=0;
        //  TC - O(n^3)
        // for(int i=0;i<n;i++){
        //     string t = "";
        //     for(int j=1;j<=n-i;j++){
        //         t+=s[i+j-1];
        //         if(isPalin(t)) res++;
        //     }
        // }
        
        //  TC - O(n^2)
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j) dp[i][j] = 1;
                else if(i+1==j) dp[i][j] = s[i]==s[j] ? 1: 0;
                else dp[i][j] = s[i]==s[j] ? dp[i+1][j-1]:0;
                res+=dp[i][j];
            }
        }
        
        return res;
    }
};