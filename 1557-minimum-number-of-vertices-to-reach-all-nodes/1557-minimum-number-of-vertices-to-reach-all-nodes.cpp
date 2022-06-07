class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>inDegree(n,0);
        vector<int>res;
        for(auto& i:edges){
            inDegree[i[1]]++;
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) res.push_back(i);
        }
        return res;
    }
};