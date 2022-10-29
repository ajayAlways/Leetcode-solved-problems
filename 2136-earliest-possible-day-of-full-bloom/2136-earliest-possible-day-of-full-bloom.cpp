// struct comp{
//     bool operator()(pair<int,int> const& a, pair<int,int> const& b){
//         if(a.first+a.second == b.first+b.second) return a.second < b.second;
//         return a.first+a.second < b.first+b.second;
//     }
// };

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
//         int n = plantTime.size(),day=0,res=0;
//         priority_queue<pair<int,int>,vector<pair<int,int>>,comp>maxHeap;
//         for(int i=0;i<n;i++){
//             maxHeap.push({plantTime[i],growTime[i]});
//         }
        
//         while(!maxHeap.empty()){
//             auto p = maxHeap.top();
//             maxHeap.pop();
//             p.first--;
//             if(p.first==0){
//                 res = max(res,p.second+day+1);
//             }
//             else{
//                 maxHeap.push(p);
//             }
//             day++;
//         }
        
//         return res;
        
        vector<pair<int, int>> v;
        for (auto i = 0; i < plantTime.size(); ++i)
            v.push_back({growTime[i], plantTime[i]});
        sort(begin(v), end(v));
        int res = 0;
        for (auto [g, p] : v)
            res = max(res, g) + p;
        return res;
    }
};