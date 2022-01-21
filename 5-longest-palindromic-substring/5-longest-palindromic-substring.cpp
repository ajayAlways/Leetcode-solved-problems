class Solution {
public:
    string longestPalindrome(string s) {
        vector<int>v(s.length(),0);
        int max=0,pos=0;
        if(s.length()==1){
            return s;
        }
        if(s.length()==2){
            if(s[0]==s[1]){
                return s;
            }
            else{
                return s.substr(0,1);
            }
        }
        for(int i=0;i<s.length();i++){
            for(int j=s.length()-1;j>i;j--){
                int t=i,p=j,l=j;
                while(s[t]==s[p]&&p>=t){
                    t++;
                    p--;
                }
                if(p<t){
                    v[i]=l-i+1;
                    break;
                }
            }
           if(v[i]>max){
               max=v[i];
               pos=i;
           }
        }
        if(max==0){
            return s.substr(0,1);
        }
        return s.substr(pos,max);
    }
};