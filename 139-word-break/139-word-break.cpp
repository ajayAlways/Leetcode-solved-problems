class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(auto& i:wordDict){
            set.insert(i);
        }
        vector<bool>dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(set.find(s.substr(j,i-j))!=set.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }   
        }
        return dp[s.length()];
    }
};