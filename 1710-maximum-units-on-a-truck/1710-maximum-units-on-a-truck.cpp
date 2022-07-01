class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res=0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        for(auto& i:boxTypes){
            if(truckSize==0) break;
            int boxes = min(i[0],truckSize);
            truckSize-=boxes;
            res+=(boxes*i[1]);
        }
        
        return res;
    }
};