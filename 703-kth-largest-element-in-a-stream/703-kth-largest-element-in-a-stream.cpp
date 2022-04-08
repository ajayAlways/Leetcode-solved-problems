class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size=0;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto& i:nums){
            minHeap.push(i);
            if(minHeap.size()>k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>size) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */