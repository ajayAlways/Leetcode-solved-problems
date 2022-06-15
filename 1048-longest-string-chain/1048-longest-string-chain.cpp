class Solution {
public:
    bool static comp(string& a, string& b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        int res=1, n = words.size(),j=0;
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            string word = words[i];
            m[word] = 1;
            for(int j=0;j<word.length();j++){
                string prev = word.substr(0,j)+word.substr(j+1);
                if(m.find(prev)!=m.end()){
                    m[word] = max(m[word],m[prev]+1);
                    res = max(res,m[word]);
                }
            }
        }
        
        return res;
    }
};