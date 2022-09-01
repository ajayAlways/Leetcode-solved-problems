class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length(), res=0;
        int prev=0,cur=1;
        for(int i=1;i<n;i++){
            if(s[i-1]!=s[i]){
                res+=min(prev,cur);
                prev = cur;
                cur = 1;
            }
            else cur++;
        }
        res+=min(cur,prev);
        
        return res;
    }
};