class Solution {
public:
    
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int len = num.size();
        for(int i=0;i<len-1;i++){
            if(num[i]>num[i+1]){
                num[i] = ((num[i]-'0')-1)+'0';
                for(int j=i+1;j<len;j++) num[j] = '9';
                i=-1;
            }
        }
        return stoi(num);
    }
};