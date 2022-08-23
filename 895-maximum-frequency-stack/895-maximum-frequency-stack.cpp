class FreqStack {
private:
    set<pair<int,int>>st;
    unordered_map<int,int>freq;
    vector<int>nums;
    int idx;
public:
    FreqStack() {
        st.clear();
        freq.clear();
        idx = 0;
    }
    
    void push(int val) {
        freq[val]++;
        nums.push_back(val);
        st.insert({freq[val],idx});
        idx++;
    }
    
    int pop() {
        auto top = *st.rbegin();
        freq[nums[top.second]]--;
        st.erase(top);
        return nums[top.second];
    }
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */