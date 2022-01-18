class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length()-1,l2=num2.length()-1,carry=0,sum=0,i=0;
        string ans="";
        while((l1+1) || (l2+1) || carry){
            sum=0;
            if(l1+1){
                sum=(int)num1[l1]-48;
                l1--;
            }
            if(l2+1){
                sum+=(int)num2[l2]-48;
                l2--;
            }
            sum+=carry;
            carry = sum/10;
            sum=sum%10;
            char c=sum+'0';
            ans+=c;
        }
        // for(int i=0;i<ans.length()/2;i++){
        //     char t=ans[i];
        //     ans[i]=ans[ans.length()-i-1];
        //     ans[ans.length()-i-1]=t;
        // }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};