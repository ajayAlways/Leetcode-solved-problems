class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        for(i,j;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            if(s[i]!=s[j]) return isPalindrome(s,i,j-1) || isPalindrome(s,i+1,j);
        }
        return true;
    }
};