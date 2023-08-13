class MyHashMap {
private:
    vector<int> map;
public:
    MyHashMap() {
        vector<int> vt(1000001,-1);
        this->map = vt;
    }
    
    void put(int key, int value) {
        this->map[key] = value;
    }
    
    int get(int key) {
        return this->map[key];
    }
    
    void remove(int key) {
        this->map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
