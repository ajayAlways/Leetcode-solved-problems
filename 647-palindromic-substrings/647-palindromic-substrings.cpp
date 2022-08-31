class Solution {
public:
    bool isPalin(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int n = s.length(),res=0;
        
        for(int i=0;i<n;i++){
            string t = "";
            for(int j=1;j<=n-i;j++){
                t+=s[i+j-1];
                if(isPalin(t)) res++;
            }
        }
        
        return res;
    }
};