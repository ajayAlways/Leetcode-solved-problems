class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<char>alpha(26,'0');
        vector<string>res;
        vector<char>map(26,'0');
        for(int i=0;i<words.size();i++){
            int flag = 1;
            alpha = vector<char>(26,'0');
            map = vector<char>(26,'0');
            for(int j=0;j<pattern.length();j++){
                if(map[words[i][j]-'a']!='0' && map[words[i][j]-'a']!=pattern[j]){
                    flag = 0;
                    break;
                }
                if(alpha[pattern[j]-'a']=='0'){
                    alpha[pattern[j]-'a'] = words[i][j];
                    map[words[i][j]-'a'] = pattern[j];
                }
                else{
                    if(alpha[pattern[j]-'a']!=words[i][j]){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};