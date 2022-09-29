class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxHeap;
        vector<int>res;
        for(auto& i:arr){
            maxHeap.push({abs(i-x),i});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};