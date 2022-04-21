class MyHashSet {
public:
    int hashSet[1000001];
    MyHashSet() {
        memset(hashSet,-1,sizeof(hashSet));
    }
    
    void add(int key) {
        hashSet[key]=1;
    }
    
    void remove(int key) {
        hashSet[key]=-1;
    }
    
    bool contains(int key) {
        return hashSet[key]!=-1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */