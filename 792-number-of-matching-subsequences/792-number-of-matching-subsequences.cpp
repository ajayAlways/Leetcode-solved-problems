class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(),res=0,prev=-1;
        unordered_map<char,vector<int>>m;
        for(int i=0;i<s.length();i++){
            m[s[i]].push_back(i);
        }
        for(auto& word:words){
            int i=0;
            prev = -1;
            for(;i<word.length();i++){
                auto it = upper_bound(m[word[i]].begin(),m[word[i]].end(),prev);
                if(it==m[word[i]].end()) break;
                else prev = *it;
            }
            if(i==word.length()) res++;
        }
        
        return res;
    }
};