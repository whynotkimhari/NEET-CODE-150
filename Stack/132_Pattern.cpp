class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    map<int,int> rank;

    int len = nums.size();
    int i = 0, a, b, c;

    if(len < 3) return false;

    vector<int> cp(nums.begin(), nums.end());
    sort(cp.begin(), cp.end());
    stack<int> st;

    int notAtFirst = cp[len - 2];

    for(auto &n: cp) {
      if(rank.find(n) == rank.end()) rank[n] = i++;
    }

    for(int i = 0; i < len; i++) {
      if(st.empty() && nums[i] < notAtFirst) {
        st.push(nums[i]);
        a = nums[i];
      }
      else if(st.size() == 1) {
        if(nums[i] <= st.top()) {
          st.pop();
          st.push(nums[i]);
          a = st.top();
        }
        else {
          if(rank[nums[i]] > rank[st.top()] + 1) {
            st.push(nums[i]);
            b = st.top();
          }
        }
      }
      else if(st.size() == 2) {
        if(nums[i] > st.top()) {
          st.pop();
          st.push(nums[i]);
          b = st.top();
        }
        else {
          if(nums[i] > a && nums[i] < b) {
            st.push(nums[i]);
            c = st.top();
          }
        }
      }
      else if(st.size() == 3) return true;
    }
    return st.size() == 3;
  } 
};
