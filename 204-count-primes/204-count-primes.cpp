class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int>primes(n,0);
        int res=1,upper=sqrt(n);
        for(int i=3;i<n;i+=2){
            if(primes[i]!=1){
                res++;
                if(i>upper) continue;
                for(int j=i*i;j<n;j+=i*2) primes[j] = 1;
            }
        }
        
        return res;
    }
};