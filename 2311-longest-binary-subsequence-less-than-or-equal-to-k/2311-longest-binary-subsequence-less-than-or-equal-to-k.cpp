class Solution {

public:
    int longestSubsequence(string s, int k) {
        int n = s.length(),sum=0,pow=1,res=0,i;
        for(i=n-1;i>=0;i--){
            if(s[i]=='1'){
                res++;
                sum+=pow;
            }
            pow = pow*2;
            if(sum+pow >k) break;
        }
        for(int j=0;j<n;j++) if(s[j]=='0') res++;
        
        return res;
    }
};