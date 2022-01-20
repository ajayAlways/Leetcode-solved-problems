class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        // for(int i=0;i<strs.size();i++){
        //     string s = strs[i];
        //     vector<int>v(128,0);
        //     ans.push_back({strs[i]});
        //     for(auto j:s){
        //         v[j-'a']++;
        //     }
        //     for(int j=i+1;j<strs.size();j++){
        //         int flag =1;
        //         vector<int>v2(128,0);
        //         for(auto k:strs[j]){
        //             v2[k-'a']++;
        //         }
        //         for(int k=0;k<26;k++){
        //             if(v[k]!=v2[k]) flag=0;
        //         }
        //         if(flag){
        //             ans.back().push_back(strs[j]);
        //             strs.erase(strs.begin()+j);
        //             j--;
        //         }
        //     }
        // }
        unordered_map<string,vector<string>>m;
        for(auto& i:strs){
            string s = i;
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        for(auto& i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};