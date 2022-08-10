class Solution {
private:
    int memo[1001][1001];
public:
    
    bool isPalin(string &s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool solve(string &s, int i, int j, int &start, int &end){
        if(i>j) return false;
        if(memo[i][j]!=-1) return memo[i][j];
        if(isPalin(s,i,j)){
            int maxLen = end-start + 1, curLen = j-i+1;
            if(curLen>=maxLen){
                start = i;
                end = j;
            }
            return memo[i][j] = true;
        }
        else{
            bool temp1 = solve(s,i+1,j,start,end);
            bool temp2 = solve(s,i,j-1,start,end);
            return memo[i][j] = temp1 || temp2;
        }
        
    }
    
    string longestPalindrome(string s) {
        int start = -1, end = -1;
        memset(memo, -1 ,sizeof memo);
        int len = solve(s,0,s.length()-1,start,end);
        return s.substr(start, end-start+1);
    }
};