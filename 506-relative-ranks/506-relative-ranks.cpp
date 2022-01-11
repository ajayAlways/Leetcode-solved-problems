class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>maxHeap;
        vector<string>ans(score.size(),"");
        for(int i=0;i<score.size();i++){
            maxHeap.push({score[i],i});
        }
        for(int i=0;i<score.size();i++){
            if(i==0) ans[maxHeap.top().second] = "Gold Medal";
            else if(i==1) ans[maxHeap.top().second] = "Silver Medal";
            else if(i==2) ans[maxHeap.top().second] = "Bronze Medal";
            else{
                ans[maxHeap.top().second] = to_string(i+1);
            }
            maxHeap.pop();
        }
        return ans;
    }
};