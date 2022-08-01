class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),maxi=-1,res=0;
        vector<int>rightMax(n,-1);
        for(int i=n-1;i>=0;i--){
            rightMax[i] = maxi;
            maxi = max(maxi,prices[i]);
        }
        for(int i=0;i<n-1;i++){
            res = max(res,rightMax[i]-prices[i]);
        }
        
        return res;
    }
};