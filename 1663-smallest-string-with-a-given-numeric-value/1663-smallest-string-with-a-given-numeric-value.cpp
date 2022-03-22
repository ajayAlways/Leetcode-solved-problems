class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        for(int i=n;i>0;i--){
            if((k-i+1)>=26){
                res[i-1] = 'z';
                k-=26;
            }
            else {
                res[i-1]='a'+(k-i);
                k=i-1;
            }
        }
        return res;
    }
};