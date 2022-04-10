class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>record;
        int res=0;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+") record.push_back(record[record.size()-1]+record[record.size()-2]);
            else if(ops[i]=="C") record.pop_back();
            else if(ops[i]=="D") record.push_back(2*record.back());
            else record.push_back(stoi(ops[i]));
        }
        for(auto& i:record) res+=i;
        return res;
    }
};