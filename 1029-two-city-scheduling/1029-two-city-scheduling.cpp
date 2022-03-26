class Solution {
public:
    bool static comp(vector<int>v1,vector<int>v2){
        return (v1[0]-v1[1]) < (v2[0]-v2[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comp);
        int res=0;
        for(int i=0;i<costs.size();i++){
            if(i<costs.size()/2) res+=costs[i][0];
            else res+=costs[i][1];
        }
        return res;
    }
};