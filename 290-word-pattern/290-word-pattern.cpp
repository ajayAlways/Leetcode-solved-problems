class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        unordered_map<char,string>m;
        unordered_set<string>st;
        int j=0;
        for(int i=0;i<=s.length();i++){
            if(s[i]==' ' || i==s.length()){
                words.push_back(s.substr(j,i-j));
                j=i+1;        
            }
        }
        if(words.size()!=pattern.length()) return false;
        for(int i=0;i<pattern.length();i++ ){
            if(m.find(pattern[i])==m.end()){
                if(st.find(words[i])!=st.end()) return false;
                m[pattern[i]]=words[i];
                st.insert(words[i]);
            }
            else{
                if(m[pattern[i]]!=words[i]) return false;
            }
        }
        return true;
    }
};