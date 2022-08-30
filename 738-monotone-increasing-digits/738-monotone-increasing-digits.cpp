class Solution {
public:
    
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int len = num.size();
        int start=len;
        for(int i=len-1;i>0;i--){
            if(num[i-1]>num[i]){
                num[i-1] = ((num[i-1]-'0')-1)+'0';
                start = i;
            }
        }
        for(int j=start;j<len;j++) num[j] = '9';
        
        return stoi(num);
    }
};