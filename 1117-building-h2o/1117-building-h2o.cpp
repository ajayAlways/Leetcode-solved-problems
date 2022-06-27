class H2O {
private:
    int i;
    mutex m;
    condition_variable cv;
public:
    H2O() {
        this->i = 1;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(i%3==0) cv.wait(lock);
        i++;
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(i%3!=0) cv.wait(lock);
        i++;
        releaseOxygen();
        cv.notify_all();
    }
};