class UndergroundSystem {
    
public:
    unordered_map<int,pair<string,int>>id2station;
    unordered_map<string,pair<int,int>>station2avg;
    
    UndergroundSystem(){}
    
    void checkIn(int id, string stationName, int t) {
        id2station[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = id2station[id].first+"-"+stationName;
        auto& p = id2station[id];
        station2avg[s].first+=t-p.second;
        station2avg[s].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation+"-"+endStation;
        int dur = station2avg[s].first;
        int times = station2avg[s].second;
        return (double)dur/times;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */