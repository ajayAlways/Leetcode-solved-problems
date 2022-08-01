class MedianFinder {
private:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
public:
    MedianFinder() {
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        int minSize = minHeap.size(), maxSize = maxHeap.size();
        if(minSize==maxSize){
            if(minHeap.top()>=num) maxHeap.push(num);
            else{
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(num);
            }
        }
        else{
            if(maxHeap.top()<=num) minHeap.push(num);
            else{
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()) return (double)(maxHeap.top()+minHeap.top())/2;
        return (double)(maxHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */