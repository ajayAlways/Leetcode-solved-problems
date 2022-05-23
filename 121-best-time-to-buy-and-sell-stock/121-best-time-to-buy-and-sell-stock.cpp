class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int>rightMax(prices.size(),0);
        // int maxi=INT_MIN,res=0;
        // for(int i=prices.size()-1;i>=0;i--){
        //     maxi=max(maxi,prices[i]);
        //     rightMax[i]=maxi;
        // }
        // for(int i=0;i<prices.size();i++){
        //     res=max(res,rightMax[i]-prices[i]);
        // }
        int res=0,mini=INT_MAX;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            res=max(res,prices[i]-mini);
        }               
        return res;
    }
};