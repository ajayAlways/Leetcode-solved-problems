class Solution {
public:
    int numSplits(string s) {
        vector<int>v1(26,0),v2(26,0);
        int left=0,right=0,ans=0;
        for(auto i:s) v2[i-'a']++;
        for(auto i:v2) if(i!=0) right++;
        for(auto i:s){
            if(v1[i-'a']==0) left++;
            if(v2[i-'a']==1) right--;
            if(left==right) ans++;
            v1[i-'a']++;
            v2[i-'a']--;
        }
        return ans;
    }
};