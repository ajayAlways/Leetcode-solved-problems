class Solution {
private:
    int t[38];
public:
    void solve(int n){
        for(int i=0;i<=n;i++){
            if(i==0) t[i]=0;
            if(i==1 || i==2) t[i]=1;
            if(i>=3) t[i] = t[i-1]+t[i-2]+t[i-3];
        }
        
    }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t));
        solve(n);
        return t[n];
    }
};