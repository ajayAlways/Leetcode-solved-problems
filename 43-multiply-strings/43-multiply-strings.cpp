class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        vector<int> sum(num1.length()+num2.length(),0);
        for(int i=num1.length()-1;i>=0;i--){
            for(int j=num2.length()-1;j>=0;j--){
                sum[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                sum[i+j]+= sum[i+j+1]/10;
                sum[i+j+1]%=10;
            }
        }
        int i=0;
        string ans="";
        while(sum[i]==0) i++;
        while(i<sum.size()) ans+=(sum[i++]+'0');
        return ans;
    }
};