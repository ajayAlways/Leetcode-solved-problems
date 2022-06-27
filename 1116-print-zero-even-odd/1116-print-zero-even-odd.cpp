class ZeroEvenOdd {
private:
    int n;
    int i;
    bool flag;
    mutex m;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;
        this->flag = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        
        while(i<=n){
            unique_lock<mutex>lock(m);
            while(!flag) cv.wait(lock);
            flag=false;
            if(i<=n){
                printNumber(0);
            }
            cv.notify_all();
        }
        
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex>lock(m);
            while(flag || i%2!=0) cv.wait(lock);
            flag=true;
            if(i<=n){
                printNumber(i);
                i++;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex>lock(m);
            while(flag || i%2==0) cv.wait(lock);
            flag=true;
            if(i<=n){
                printNumber(i);
                i++;
            }
            cv.notify_all();
        }
    }
};