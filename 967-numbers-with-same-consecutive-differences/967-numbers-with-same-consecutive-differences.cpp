class Solution {
public:
    
    void solve(int n, int k, int i,vector<int>&res,int num,int prev){
        if(i>=n){
            res.push_back(num);
            return;
        }
        int start=0;
        if(i==0) start = 1;
        for(int j=start;j<=9;j++){
            if(i==0 || abs(prev-j)==k) solve(n,k,i+1,res,num*10+j,j);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        solve(n,k,0,res,0,0);
        
        return res;
    }
};