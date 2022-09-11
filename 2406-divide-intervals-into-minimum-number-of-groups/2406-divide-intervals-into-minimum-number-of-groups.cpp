class Solution {
public:
    int minGroups(vector<vector<int>>& inter) {
        int n = inter.size();
        int prevL=-1,prevR=-1, res=0;
        vector<vector<pair<int,int>>>temp;
        sort(inter.begin(),inter.end());
        priority_queue<int,vector<int>,greater<int>>minHeap;
        minHeap.push(inter[0][1]);
        for(int i=1;i<n;i++){
            if(inter[i][0]<=minHeap.top()){
                minHeap.push(inter[i][1]);
            }
            else{
                minHeap.pop();
                minHeap.push(inter[i][1]);
            }
        }
        
        return minHeap.size();
    }
};