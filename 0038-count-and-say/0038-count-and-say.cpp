class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++){
            string temp = "";
            for(int j=0;j<res.length();j++){
                int count=0,num = res[j]-'0';
                while(j<res.length() && num==(res[j]-'0')){
                    count++;
                    j++;
                }
                temp+=to_string(count)+to_string(num);
                j--;
            }
            res=temp;
        }
        return res;
    }
};