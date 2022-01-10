class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i=a.length()-1, j=b.length()-1,carry=0;
        while(carry || i>=0 || j>=0){
            int sum=0;
            if(i+1){
                sum+=a[i]-'0';
                i--;
            }
            if(j+1){
                sum+=b[j]-'0';
                j--;
            }
            sum+=carry;
            carry=sum/2;
            sum%=2;
            char s = char(sum+'0');
            ans+=s;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};