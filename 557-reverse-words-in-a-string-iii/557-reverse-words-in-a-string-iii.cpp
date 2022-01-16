class Solution {
public:
    string reverseWords(string s) {
        int begin = 0;
        for(int i=0;i<=s.length();i++){
            if(i==s.length() || s[i]==' '){
                for(int j=0;j<(i-begin)/2;j++) swap(s[begin+j],s[i-j-1]);
                begin = i+1;
            }
        }
        return s;
    }
};