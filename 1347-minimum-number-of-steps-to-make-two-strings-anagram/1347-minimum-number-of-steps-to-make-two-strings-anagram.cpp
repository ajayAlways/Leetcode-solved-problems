class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>v(26,0);
        int ans=0;
        for(auto i:s) v[i-'a']++;
        for(auto i:t){
            if(v[i-'a']) v[i-'a']--;
        }
        for(auto i:v) ans+=i;
        return ans;
    }
};