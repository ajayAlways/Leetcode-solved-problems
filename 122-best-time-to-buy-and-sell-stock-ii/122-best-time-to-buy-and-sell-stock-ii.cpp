class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int buy=0,sell=0,profit=0,i=0,n=prices.size()-1;
        while(i<n){
            while(i<n && prices[i]>=prices[i+1]) i++;
            buy=i;
            while(i<n && prices[i]<prices[i+1]) i++;
            sell = i;
            profit+=(prices[sell]-prices[buy]);
        }
        return profit;
    }
};