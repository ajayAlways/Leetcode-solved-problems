class Solution {
private:
    // unordered_map<string,int>memo;
public:
    
//     int findLen(string &s){
//         string res="";
//         int n=s.length(), i=0;
//         while(i<n){
//             char t = s[i];
//             int cnt=0;
//             while(i<n && s[i]==t){
//                 cnt++;
//                 i++;
//             }
//             if(cnt>1) res+=t+to_string(cnt);
//             else res+=t;
//         }
        
//         return res.length();
//     }
    
    
//     int solve(string &s,string &curStr, int i, int k){
//         if(i>=s.length()){
//             return findLen(curStr);
//         }
        
//         if(k==0){
//             string temp = curStr;
//             curStr+=s.substr(i);
//             int len = findLen(curStr);
//             curStr = temp;
//             return len;
//         }
        
//         string hash = to_string(i)+'$'+to_string(k);
//         if(memo.find(hash)!=memo.end()) return memo[hash];
        
//         int remove = solve(s,curStr, i+1,k-1);
//         curStr+=s[i];
//         int notRemove = solve(s,curStr,i+1,k);  
//         curStr.pop_back();
//         return memo[hash] = min(remove,notRemove);
//     }
    
//     int getLengthOfOptimalCompression(string s, int k) {
//         string curStr = "";
//         return solve(s,curStr,0,k);
//     }
    
    int dp[101][101];
    int dfs(string &s, int left, int K) {
        int k = K;
        if(s.size() - left <= k) return 0;
        if(dp[left][k] >= 0) return dp[left][k];
        int res = k ? dfs(s, left + 1, k - 1) : 10000, c = 1;
        for(int i = left + 1; i <= s.size(); ++i) {
            res = min(res, dfs(s, i, k) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 :0))));
            if(i == s.size()) break;
            if(s[i] == s[left]) ++c;
            else if(--k < 0) break;
        }
        return dp[left][K] = res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, k);
    }
};