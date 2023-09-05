#define pss pair<string,string>
#define vi vector<int>

class Obj {
    public:
        int t;
        string stationName;
    
    Obj(string stationName, int t) {
        this->stationName = stationName;
        this->t = t;
    };
};

class UndergroundSystem {
private:
    map<int, Obj*> MMap;
    map<pss, vi> trips;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        Obj* unit = new Obj(stationName, t);
        this->MMap[id] = unit;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto unit = MMap[id];
        pss key = {unit->stationName, stationName};
        auto time = t - unit->t;

        if(trips[key].size()) trips[key].push_back(time);

        else {
            vi tmp;
            tmp.push_back(time);
            trips[key] = tmp;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto trip = trips[{startStation, endStation}];
        double sum = 0;

        for(auto &t: trip) sum += t;
        sum /= trip.size();

        return sum;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
