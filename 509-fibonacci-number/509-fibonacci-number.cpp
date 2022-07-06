class Solution {
public:
    int fib(int n) {
        int a=1,b=0;
        if(n<2) return n;
        for(int i=2;i<=n;i++){
            int temp = a;
            a=a+b;
            b=temp;
        }
        return a;
    }
};