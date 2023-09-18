#define si set<int>

class RandomizedSet {
private:
  si s;
public:
    RandomizedSet() {
      si s;
      this->s = s;
    }
    
    bool insert(int val) {
      bool flag = (this->s.find(val) != this->s.end()) ? 0 : 1;
      this->s.insert(val);
      return flag;
    }
    
    bool remove(int val) {
      auto it = this->s.find(val);
      bool flag = (it != this->s.end()) ? 1 : 0;
      if(!flag) return flag;
      
      this->s.erase(it);
      return flag;
    }
    
    int getRandom() {
      int ranNum = rand() % this->s.size();
      auto it = this->s.begin();
      while(ranNum--) it++;
      return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
