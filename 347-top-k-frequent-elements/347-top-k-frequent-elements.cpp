class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>res;
        for(auto& i:nums) m[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for(auto& i:m){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k) minHeap.pop();
        }
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};