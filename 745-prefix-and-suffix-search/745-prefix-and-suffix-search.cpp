class WordFilter {
private:
    unordered_map<string,int>hashMap;
public:
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string word = words[i],pref="";
            for(int j=0;j<word.size();j++){
                pref+=word[j];
                string suf;
                for(int k=0;k<word.size();k++){
                    suf = word.substr(k);
                    hashMap[pref+"|"+suf] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix+"|"+suffix;
        if(hashMap.find(s)!=hashMap.end()) return hashMap[s]-1;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */