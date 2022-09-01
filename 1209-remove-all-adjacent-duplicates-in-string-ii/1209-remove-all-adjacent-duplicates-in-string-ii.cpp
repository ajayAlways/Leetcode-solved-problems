class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        string res="";
        vector<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.back().first==s[i]) st.back().second++;
            else st.push_back({s[i],1});
            if(!st.empty() && st.back().second==k) st.pop_back();
        }
        for(auto i:st){
            res.append(i.second,i.first);
        }
        
        return res;
    }
};