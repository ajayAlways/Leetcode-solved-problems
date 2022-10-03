class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size(), prev = 0, res=0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[prev]){
                int mini=min(neededTime[prev],neededTime[i]);
                res+=mini;
                if(neededTime[prev]==mini) prev = i;
            }
            else prev = i;
        }
        
        return res;
    }
};