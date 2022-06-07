class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res=0;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        queue<string>q;
        unordered_set<string>m(wordList.begin(),wordList.end());
        q.push(beginWord);
        if(m.find(endWord)==m.end()) return 0;
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i=0;i<size;i++){
                string str = q.front();
                q.pop();
                if(str==endWord) return res;
                for(int j=0;j<str.length();j++){
                    char c = str[j];
                    for(int k=0;k<26;k++){
                        str[j] = alpha[k];
                        if(m.find(str)!=m.end()){
                            q.push(str);
                            m.erase(str);
                        }
                    }
                    str[j] = c;
                }
            }
        }
        return 0;
    }
};