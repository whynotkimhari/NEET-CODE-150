class Solution {
public:
  int maximumRemovals(string s, string p, vector<int>& removable) {
    int left = 0;
    int right = removable.size();
    
    while (left < right) {
      int mid = left + (right - left + 1) / 2; // Use upper-bound binary search
      if (canRemove(s, p, removable, mid)) {
          left = mid;
      } else {
          right = mid - 1;
      }
    }
    
    return left;
  }
  
  bool canRemove(const string& s, const string& p, const vector<int>& removable, int k) {
    string modifiedS = s;
    
    for (int i = 0; i < k; ++i) {
        modifiedS[removable[i]] = '*'; // Mark removable characters
    }
    
    int x = 0, y = 0;
    while (x < modifiedS.size() && y < p.size()) {
        if (modifiedS[x] == p[y]) {
            ++y;
        }
        ++x;
    }
    
    return y == p.size();
  }
};
