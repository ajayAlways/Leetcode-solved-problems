class Solution {
public:
    vector<int> pascalRow(vector<int>prevRow){
        int n = prevRow.size();
        vector<int>res(n+1,1);
        for(int i=1;i<n;i++){
            res[i] = prevRow[i-1]+prevRow[i];
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>res;
        res.push_back({1});
        if(n==1) return res;
        res.push_back({1,1});
        if(n==2) return res;
        for(int i=3;i<=n;i++){
            res.push_back(pascalRow(res.back()));
        }
        return res;
    }
};