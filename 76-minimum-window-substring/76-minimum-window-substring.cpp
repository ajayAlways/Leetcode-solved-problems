class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>pat_m(256,0);
        vector<int>str_m(256,0);
        int n = s.length(), m = t.length(),match=0,minLen=n+1,startIdx=-1,start=0;
        if(m>n) return "";
        for(auto i:t) pat_m[i]++;
        for(int i=0;i<n;i++){
            str_m[s[i]]++;
            if(pat_m[s[i]]>=str_m[s[i]]) match++;
            if(match==m){
                while(!pat_m[s[start]] || str_m[s[start]]>pat_m[s[start]]){
                    if(str_m[s[start]]>pat_m[s[start]]) str_m[s[start]]--;
                    start++;
                }
                int len = i - start + 1;
                if(len<minLen){
                    minLen = len;
                    startIdx = start;
                }
            }
        }
        if(startIdx==-1) return "";
        return s.substr(startIdx,minLen);
    }
};