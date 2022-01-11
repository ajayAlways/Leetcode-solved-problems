class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push({nums[i],i});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int> temp(nums.size(),INT_MIN),ans;
        for(int i=0;i<nums.size();i++){
            temp[minHeap.top().second] = minHeap.top().first;
            minHeap.pop();
        }
        for(int i=0;i<nums.size();i++) if(temp[i]!=INT_MIN) ans.push_back(temp[i]);
        return ans;
    }
};