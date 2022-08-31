class Solution {
public:
    int countPrimes(int n) {
        vector<int>primes(n,0);
        int res=0;
        for(int i=2;i<n;i++){
            if(primes[i]!=1){
                res++;
                for(int j=2*i;j<n;j+=i) primes[j] = 1;
            }
        }
        
        return res;
    }
};