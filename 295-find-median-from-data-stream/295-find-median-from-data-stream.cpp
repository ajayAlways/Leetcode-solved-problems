class MedianFinder {
private:
    priority_queue<long>maxHeap;
    priority_queue<long,vector<long>,greater<long>>minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()) return (double)(minHeap.top()+maxHeap.top())/2.0;
        else return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */