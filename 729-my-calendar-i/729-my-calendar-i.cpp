class MyCalendar {
private:
    vector<pair<int,int>>events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(events.empty()){
            events.push_back({start,end});
            return true;
        }
        for(auto& i:events){
            if(max(start,i.first)<min(end,i.second)) return false;
        }
        events.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */