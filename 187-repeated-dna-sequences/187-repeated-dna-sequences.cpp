class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10) return {};
        unordered_map<string,int>m;
        vector<string>ans;
        for(int i=0;i<=s.length()-10;i++){
            m[s.substr(i,10)]++;
        }
        for(auto& i:m){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;
    }
};