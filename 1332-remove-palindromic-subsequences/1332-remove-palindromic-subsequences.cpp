class Solution {
public:
    bool check(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(check(s)) return 1;
        return 2;
    }
};