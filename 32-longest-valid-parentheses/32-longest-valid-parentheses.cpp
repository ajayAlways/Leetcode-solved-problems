class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(),res=0,left=0,right=0;
        // O(n^2) - Time Brute Force         
        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         int count=0,open=0;
        //         for(int j=i;j<n;j++){
        //             count++;
        //             if(s[j]=='(') open++;
        //             else {
        //                 if(open!=0){
        //                     open--;
        //                     if(open==0) res = max(res,count);
        //                 }
        //                 else count=0;
        //             }
        //         }
        //     }   
        // }
        for(int i=0;i<n;i++){
            if(s[i]=='(') left++;
            else right++;
            if(left==right) res = max(res,right*2);
            if(right>left) left=right=0;
        }
        left=right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') left++;
            else right++;
            if(left==right) res = max(res,left*2);
            if(left>right) left=right=0;
        }
        return res;
    }
};