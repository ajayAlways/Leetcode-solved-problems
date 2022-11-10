class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(int i=0;i<s.length();i++){
            if(res.empty() || res.back()!=s[i]){
                res+=s[i];
            }
            else res.pop_back();
        }
        
        return res;
    }
};