class RandomizedSet {
private:
    unordered_map<int,int>Map;
    vector<int>nums;
public:
    RandomizedSet() {
        Map.clear();
        nums.clear();
    }
    
    bool insert(int val) {
        if(Map.find(val)!=Map.end()) return false;
        nums.push_back(val);
        Map[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(Map.find(val)==Map.end()) return false;
        int pos = Map[val],last = nums.back();
        swap(nums[Map[val]],nums[nums.size()-1]);
        Map[last] = pos;
        Map.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */