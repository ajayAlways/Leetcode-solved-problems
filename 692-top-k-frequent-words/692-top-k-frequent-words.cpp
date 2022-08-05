struct comp{
  constexpr bool operator()(pair<int,string>const &a, pair<int,string>const &b){
      if(a.first==b.first) return a.second<b.second;
      return a.first>b.first;
  }  
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>minHeap;
        vector<string>res(k);
        for(auto& word:words){
            m[word]++;
        }
        for(auto& i:m){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k) minHeap.pop();
        }
        int idx=k-1;
        while(!minHeap.empty()){
            res[idx--] = minHeap.top().second;
            minHeap.pop();
        }
        
        return res;
    }
};