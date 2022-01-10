class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size(),false);
        vector<vector<int>>prefix;
        vector<int>temp(26,0);
        prefix.push_back(temp);
        for(int i=0;i<s.length();i++){
            temp[s[i]-'a']++;
            prefix.push_back(temp);
        }
        for(int i=0;i<queries.size();i++){
        int count=0,l=queries[i][0],h=queries[i][1],num=queries[i][2];
        vector<int>temp = prefix[h+1];
        for(int i=0;i<26;i++){
            temp[i]-=prefix[l][i];
            count+=temp[i]%2;
        }
        ans[i] = count<=2*num+(h-l+1)%2;
        }
        return ans;
    }
};