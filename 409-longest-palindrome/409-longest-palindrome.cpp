class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>v(128,0);
        for(auto i:s) v[(int)i]++;
        int ans=0;
        for(auto i:v){
            ans+=i/2 * 2;
            if(ans%2==0 && i%2==1) ans++;
        }
        return ans;
    }
};