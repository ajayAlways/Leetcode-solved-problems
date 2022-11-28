class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>w,l;
        vector<vector<int>>res;
        res.push_back({});
        res.push_back({});
        for(auto& i:matches){
            w[i[0]]++;
            l[i[1]]++;
        }
        for(auto& i:l){
            if(i.second==1) res[1].push_back(i.first);
        }
        for(auto& i:w){
            if(l.find(i.first)==l.end()){
                res[0].push_back(i.first);
            }
        }
        
        sort(res[0].begin(),res[0].end());
        sort(res[1].begin(),res[1].end());
        
        return res;
    }
};