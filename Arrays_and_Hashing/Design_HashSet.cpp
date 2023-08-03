class MyHashSet {
private:
    vector<int> HashSet;

public:
    MyHashSet() {
        vector<int> v(1000001, -1);
        this->HashSet = v;
    }
    
    void add(int key) {
        this->HashSet[key] = key;
    }
    
    void remove(int key) {
        this->HashSet[key] = -1;
    }
    
    bool contains(int key) {
        return (this->HashSet[key] != -1);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
