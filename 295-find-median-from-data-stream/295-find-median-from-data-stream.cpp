class MedianFinder {
private:
    priority_queue<long>maxHeap;
    priority_queue<long,vector<long>,greater<long>>minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHeap.empty()) maxHeap.push(num);
        else if(maxHeap.size()==minHeap.size()){
            int temp = minHeap.top();
            if(num<=temp) maxHeap.push(num);
            else{
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }
        else{
            int temp = maxHeap.top();
            if(temp<=num) minHeap.push(num);
            else{
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
            }
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