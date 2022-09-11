class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1e9+7;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({efficiency[i],speed[i]});
        }
        sort(p.begin(),p.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>>minHeap;
        long long sum=0,res=0;
        for(auto& [e,s]:p){
            minHeap.push(s);
            sum+=s;
            if(minHeap.size()>k){
                sum-=minHeap.top();
                minHeap.pop();
            }
            res = max(res,e*sum);
        }
        
        return res%mod;
    }
};