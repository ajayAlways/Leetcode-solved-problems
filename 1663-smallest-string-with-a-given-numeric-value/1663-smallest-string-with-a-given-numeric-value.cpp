class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for(int i=n;i>0;i--){
            if((k-i+1)>=26){
                res.push_back('z');
                k-=26;
            }
            else {
                res.push_back('a'+(k-i));
                k=i-1;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};