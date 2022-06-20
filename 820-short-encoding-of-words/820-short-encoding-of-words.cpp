class Solution {
public:
    bool static comp(string& a, string& b){
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(),comp);
        unordered_set<string>st;
        string res="";
        for(auto& word:words){
            string temp = word;
            int flag = 0;
            if(res.length()==0){
                res+=temp+'#';
                flag = 1;
            }
            else{
                if(st.find(temp)!=st.end()) continue;
                else{
                    res+=temp+'#';
                    flag=1;
                } 
            }
            if(flag){
                for(int i=0;i<temp.length();i++){
                    st.insert(temp.substr(i));
                }
            }
        }
        return res.length();
    }
};