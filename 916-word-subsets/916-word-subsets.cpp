class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        int n = words1.size();
        vector<int>freq(26,0);
        for(auto& i:words2){
            vector<int>temp(26,0);
            for(auto& j:i) temp[j-'a']++;
            for(int k=0;k<26;k++) freq[k] = max(temp[k],freq[k]);
        }
        for(auto& i:words1){
            vector<int>temp(26,0);
            int flag=1;
            for(auto& j:i) temp[j-'a']++;
            for(int k=0;k<26;k++){
                if(temp[k]<freq[k]){
                    flag = 0;
                    break;
                }
            }
            if(flag) res.push_back(i);
        }
        
        return res;
    }
};