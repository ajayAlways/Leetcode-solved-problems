class Solution {
public:
    bool check(vector<int>a1, vector<int>a2){
        for(int i=0;i<a1.size();i++){
            if(a1[i]!=a2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        if(s1.length()>s2.length()) return false;
        
        for(auto i:s1) arr1[i-'a']++;
        int j=0;
        for(int i=0;i<s2.length();i++){
            arr2[s2[i]-'a']++;
            if(i>=s1.size()){
                arr2[s2[j]-'a']--;
                j++;
            }
            if(check(arr1,arr2)) return true;
        }
        return check(arr1,arr2);
    }
};