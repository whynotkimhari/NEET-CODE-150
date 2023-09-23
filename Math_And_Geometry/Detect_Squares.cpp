#define pii pair<int, int>
#define mpiii map<pii, int>
#define vpii vector<pii>
#define vi vector<int>

class DetectSquares {
private:
  mpiii initalSpace;
public:
  DetectSquares() {
    mpiii newSpace;
    this->initalSpace = newSpace;
  }
  
  void add(vector<int> point) {
    pii p = {point[0], point[1]};
    if(this->initalSpace.find(p) != this->initalSpace.end()) this->initalSpace[p]++;
    else this->initalSpace[p] = 1;
  }
  
  int count(vector<int> point) {
    int cnt = 0;
    pii p1 = {point[0], point[1]};
    vpii row;

    // We just need to check all the points in the same row because of if the
    // Square exist, there will exist a point in the same row
    // There is no case that {
    //    + Exist a square
    //    + Not exist a point in the same row
    //    + Exist a point in the same column  
    // }
    // So we just implement just row or column

    for(auto &key: this->initalSpace) {
      if(key.first.first == p1.first) row.push_back(key.first);
    }

    for(auto &pt: row) {
      int len = p1.second - pt.second;
      if(len != 0) {
        // Check 2 possible sq to the left of the point
        pii tmp1 = {p1.first - len, p1.second}, tmp2 = {p1.first - len, p1.second - len};
        if(
          this->initalSpace.find(tmp1) != this->initalSpace.end() &&
          this->initalSpace.find(tmp2) != this->initalSpace.end()
        ) cnt = cnt + this->initalSpace[pt] * this->initalSpace[tmp1] * this->initalSpace[tmp2];

        // Check 2 possible sq to the right of the point
        pii tmp3 = {p1.first + len, p1.second}, tmp4 = {p1.first + len, p1.second - len};
        if(
          this->initalSpace.find(tmp3) != this->initalSpace.end() &&
          this->initalSpace.find(tmp4) != this->initalSpace.end()
        ) cnt = cnt + this->initalSpace[pt] * this->initalSpace[tmp3] * this->initalSpace[tmp4];
      }
      else continue;
    }
    return cnt;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
