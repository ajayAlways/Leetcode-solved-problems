class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>freq;
        int j=0,res=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'0']++;
            if(freq[s[i]-'0']==1) res = max(res,i-j+1);
            while(freq[s[i]-'0']>1){
                freq[s[j]-'0']--;
                j++;
            }
        }
        return res;
    }
};