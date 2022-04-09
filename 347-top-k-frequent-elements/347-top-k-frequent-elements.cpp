class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        unordered_map<int,int>m;
        vector<int>res(k);
        for(auto& i:nums){
            m[i]++;
        }
        for(auto& i:m){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k) minHeap.pop();
        }
        while(k--){
            res[k]= minHeap.top().second;
            minHeap.pop();
        }
        
        return res;
        
    }
};