class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>2){
                minHeap.pop();
            }
        }
        int h = minHeap.top();
        minHeap.pop();
        return (h-1)*(minHeap.top()-1);
    }
};