class Solution {
public:
    int countVowelPermutation(int n) {
        string vowels = "aeiou";
        vector<vector<char>>mapping = {{'e'},{'a','i'},{'a','e','o','u'},{'i','u'},{'a'}};
        unordered_map<char,vector<char>>m1;
        unordered_map<char,long long>m2;
        for(int i=0;i<5;i++){
            m1[vowels[i]] = mapping[i];
            m2[vowels[i]]++;
        }
        int mod = 1e9+7;
        long long res = 5;
        for(int i=2;i<n;i++){
            unordered_map<char,long long>temp = m2;
            m2.clear();
            for(auto& i:vowels){
                for(auto& j:m1[i]){
                    m2[j]+=temp[i]%mod;
                }
            }
        }
        if(n>1){
            res = 0;
            for(auto& i:m2){
                res = (res + (i.second*m1[i.first].size()*1LL)%mod)%mod;
            }    
        }
        
        return res;
    }
};