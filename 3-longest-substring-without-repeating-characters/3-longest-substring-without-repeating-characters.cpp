class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>ss;
        int j=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(ss.find(s[i])==ss.end()){
                ans = max(i-j+1,ans);
            }
            while(ss.find(s[i])!=ss.end()){
                ss.erase(s[j++]);
            }
            
            ss.insert(s[i]);
        }
        return ans;
    }
};