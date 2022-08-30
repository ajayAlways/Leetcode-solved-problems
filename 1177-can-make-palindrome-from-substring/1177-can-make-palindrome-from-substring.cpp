class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>>freq;
        vector<int>temp(26,0);
        vector<bool>res;
        freq.push_back(temp);
        for(int i=0;i<n;i++){
            temp[s[i]-'a']++;
            freq.push_back(temp);
        }
        for(auto& i:queries){
            int odds=0;
            for(int j=0;j<26;j++){
                if((freq[i[1]+1][j] - freq[i[0]][j])%2!=0) odds++;
            }
            if(odds/2 <=i[2]) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};