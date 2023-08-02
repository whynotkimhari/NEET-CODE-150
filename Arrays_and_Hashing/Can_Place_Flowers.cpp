class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1) {
            if(flowerbed[0] && n) return false;
            if(flowerbed[0] && !n) return true;
            if(!flowerbed[0] && n <= 1) return true;
            return false; 
        }

        if(!n) return true;

        
        if(!flowerbed[0] && !flowerbed[1]) {
            n--;
            flowerbed[0] = 1;
        }

        if(!n) return true;

        if(!flowerbed[flowerbed.size()-1] && !flowerbed[flowerbed.size()-2]) {
            flowerbed[flowerbed.size()-1] = 1;
            n--;
        }

        if(!n) return true;

        for(int i = 1; i < flowerbed.size()-2; i++) {
            if(flowerbed[i]) continue;
            else {
                if(!flowerbed[i-1] && !flowerbed[i+1]) {
                    flowerbed[i] = 1;
                    n--;
                }
            }

            if(!n) return true;
        }

        if(n) return false;
        return true;
    }
};
