class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            vector<int>v(26,-1);
            unordered_set<int>ss;
            int flag=1;
            for(int j=0;j<pattern.length();j++){
                if(v[pattern[j]-'a']==-1 && ss.find(words[i][j]-'a')==ss.end()){
                    v[pattern[j]-'a'] = words[i][j]-'a';
                    ss.insert(words[i][j]-'a');
                }
                else{
                    if(v[pattern[j]-'a'] != words[i][j]-'a') flag=0;
                }
            }
            if(flag) ans.push_back(words[i]);
        }
        return ans;
    }
};