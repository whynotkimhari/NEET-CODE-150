// NOT IMPLEMENT BS, BUT A NORMAL LOOP

#define pss pair<string,string>
#define mipss map<int, pss>
class TimeMap {
private:
    mipss MMap;
    vector<int> vals;
public:
    TimeMap() {
        mipss tmp;
        vector<int> v;
        this->MMap = tmp;
        this->vals = v;
    }
    
    void set(string key, string value, int timestamp) {
        this->MMap[timestamp] = {key, value};
        if(this->vals.size() > 0) {
            if(timestamp != this->vals.back()) {
                this->vals.push_back(timestamp);
            }
        }
        else this->vals.push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        int left = 0, right = timestamp;
        string rt = "";
        if(timestamp > this->vals.back()) timestamp = this->vals.back();
        
        while(true) {
            if(this->MMap.find(timestamp) != this->MMap.end() && this->MMap[timestamp].first == key) {
                rt = this->MMap[timestamp].second;
                break;
            }
            else {
                timestamp--;
                if(timestamp < 0) break;
            }
        }
        return rt;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
