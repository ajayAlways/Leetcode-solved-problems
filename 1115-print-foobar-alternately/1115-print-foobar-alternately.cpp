class FooBar {
private:
    int n;
    int j;
    mutex m;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        this->j = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex>lock(m);
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            while(j%2!=0) cv.wait(lock);
        	printFoo();
            j++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex>lock(m);
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            while(j%2==0) cv.wait(lock);
        	printBar();
            j++;
            cv.notify_all();  
        }
    }
};