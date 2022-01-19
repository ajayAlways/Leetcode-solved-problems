

bool isNumber(char c){
    return c-'0'>=0 && c-'0'<10;
}


void solve(string ip,string op,vector<string>&ans){
    if(ip.length()==0){
        ans.push_back(op);
        return;
    }
    if(isNumber(ip[0])){
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1,ans);
    }
    else{
        string op1 = op, op2 = op;
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin()+0);
        solve(ip,op1,ans);    
        solve(ip,op2,ans);
    }
    
}

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string op="";
        vector<string>ans;
        solve(s,op,ans);
        return ans;
    }
};