class MyCircularQueue {
private:
    vector<int>q;
    int curSize,maxSize,front,back;
public:
    MyCircularQueue(int k) {
        q = vector<int>(k,0);
        maxSize = k;
        curSize = 0;
        front = 0;
        back = -1;
    }
    
    bool enQueue(int value) {
        if(curSize==maxSize) return false;
        back = (back+1)%maxSize;
        q[back] = value;
        curSize++;
        return true;
    }
    
    bool deQueue() {
        if(curSize==0) return false;
        front = (front+1)%maxSize;
        curSize--;
        return true;
    }
    
    int Front() {
        if(curSize==0) return -1;
        return q[front];
    }
    
    int Rear() {
        if(curSize==0) return -1;
        return q[back];
    }
    
    bool isEmpty() {
        return curSize==0;
    }
    
    bool isFull() {
        return curSize==maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */