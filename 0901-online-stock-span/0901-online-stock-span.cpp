class StockSpanner {
private:
    vector<pair<int,int>>nums;
public:
    StockSpanner() {}
    
    int next(int price) {
        int res=1;
        while(!nums.empty() && nums.back().first<=price){
            res+=nums.back().second;
            nums.pop_back();
        }
        nums.push_back({price,res});
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */