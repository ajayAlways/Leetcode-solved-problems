class LRUCache {
private:
    int cap;
    list<pair<int,int>>lru;
    unordered_map<int,list<pair<int,int>>::iterator>cache;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        lru.splice(lru.begin(),lru,cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key]->second = value;
            lru.splice(lru.begin(),lru,cache[key]);
        }
        else{
            if(cache.size()==cap){
                auto del_key = lru.back().first;
                lru.pop_back();
                cache.erase(del_key);
            }
            lru.push_front({key,value});
            cache[key] = lru.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */