class Foo {
private:
    mutex m;
    condition_variable c;
    int i;
public:
    Foo() {
        i = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        while(i!=1){
            c.wait(lock);
        }
        i++;
        printFirst();
        c.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        while(i!=2){
            c.wait(lock);
        }
        i++;
        printSecond();
        c.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        while(i!=3){
            c.wait(lock);
        }
        i++;
        printThird();
        c.notify_all();
    }
};