class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(),res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                int count=0,open=0;
                for(int j=i;j<n;j++){
                    count++;
                    if(s[j]=='(') open++;
                    else {
                        if(open!=0){
                            open--;
                            if(open==0) res = max(res,count);
                        }
                        else count=0;
                    }
                }
            }   
        }
        return res;
    }
};