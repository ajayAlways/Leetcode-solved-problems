class Solution {
public:
    
//     void add(int n, long long &res){
//         int mod = 1e9+7;
//         stack<int>st;
//         while(n){
//             st.push(n%2);
//             n/=2;
//         }

//         while(!st.empty()){
//             res*=2;
//             res%=mod;
//             res+=st.top();
//             st.pop();
//         }
//     }
    
//     int concatenatedBinary(int n) {
//         long long res = 0;
//         int mod = 1e9+7;
        
//         for(int i=1;i<=n;i++){
//             add(i,res);
//         }
        
//         return res;
//     }
    int numberOfBits(int n) {
		  return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};