class Solution {
public:
    
    int solve(int n, int i, unordered_set<int>&st){
        if(i>n) return 1;
        int res = 0;
        for(int k=1;k<=n;k++){
            if(!st.count(k) && (i%k==0 || k%i==0)){
                st.insert(k);
                res+=solve(n,i+1,st);
                st.erase(k);
            }
        }
        
        return res;
    }
    
    int countArrangement(int n) {
        unordered_set<int>st;
        return solve(n,1,st);
    }
};