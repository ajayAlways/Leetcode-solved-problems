class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,0);
        int j=0,count=0;
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0){
                v[s[j]-'a']--;
                j++;
            }
            count+=j;
        }
        return count;
    }
};