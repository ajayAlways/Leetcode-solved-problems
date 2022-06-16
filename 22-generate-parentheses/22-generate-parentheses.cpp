class Solution {
public:
    void solve(string s,int open, int close,vector<string>& res){
        if(open==0 && close==0){
            res.push_back(s);
            return;
        }
        if(open==close) solve(s+'(',open-1,close,res);
        else{
            if(close!=0) solve(s+')',open,close-1,res);
            if(open!=0) solve(s+'(',open-1,close,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve("",n,n,res);
        return res;
    }
};