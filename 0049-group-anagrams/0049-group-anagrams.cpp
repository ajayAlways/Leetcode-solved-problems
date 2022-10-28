class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,int>Map;
        for(auto& i:strs){
            string temp = i;
            sort(temp.begin(),temp.end());
            if(Map.find(temp)==Map.end()){
                res.push_back({i});
                Map[temp] = res.size()-1;
            }
            else{
                res[Map[temp]].push_back(i);
            }
        }
        
        return res;
    }
};