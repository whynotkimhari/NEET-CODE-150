class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int val1 = 1, val2 = 0;
    int type1 = fruits[0], type2 = -1;
    int max = INT_MIN;
    int strk1 = 1, strk2 = 1;
    
    for(int i = 1; i < fruits.size(); i++) {
      if(fruits[i] == type1) {
        val1++;
        if(fruits[i - 1] == type1) strk1++;
        else strk1 = 1;
      }
      else {
        if(type2 == -1) {
          type2 = fruits[i];
          val2++;
          strk2 = 1;
        }
        else {
          if(type2 == fruits[i]) {
            val2++;
            if(fruits[i - 1] == type2) strk2++;
            else strk2 = 1;

          }
          else {
            if(max < val1 + val2) max = val1 + val2;
            if(type1 != fruits[i - 1]) {
              type1 = fruits[i - 1];
              type2 = fruits[i];

              val1 = strk2;
              strk1 = strk2;

              val2 = 1;
              strk2 = 1;
            }
            else {
              val1 = strk1;
              type2 = fruits[i];

              val2 = 1;
              strk2 = 1;
            }
            
          }
        }
      }
    }
    if(max < val1 + val2) max = val1 + val2;
    return max;
  }
};
