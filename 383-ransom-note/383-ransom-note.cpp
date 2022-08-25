class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(auto& i:ransomNote) f1[i-'a']++;
        for(auto& i:magazine) f2[i-'a']++;
        
        for(auto& i:ransomNote){
            if(f1[i-'a']>f2[i-'a']) return false;
        }
        
        return true;
    }
};