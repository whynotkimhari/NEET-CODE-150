class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -1;
        int start = 0, end = height.size() - 1;
        int h;
        while(start < end) {
            h = (max(height[start], height[end]) - abs(height[start] - height[end])) * abs(start - end);
            if(h > ans) ans = h;

            if(height[start] > height[end]) end--;
            else start++;
        }
        return ans;
    }
}; 
