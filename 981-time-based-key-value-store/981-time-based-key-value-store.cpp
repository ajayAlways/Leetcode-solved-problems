class TimeMap {
private:
    unordered_map<string,map<int,string>>m;
public:
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto t = m[key].upper_bound(timestamp);
        return t==m[key].begin() ? "":prev(t)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */