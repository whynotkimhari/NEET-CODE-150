// Solution 1: O(n^2) time -- Kind of bad
class Solution {
public:
    int count(vector<int> &arr, int &base) {
        int i = 0, answer = 0, tmp = 0;
        while(!(arr[i] > base)) i++;
        while(i < arr.size()) {
            if(arr[i] > base) {
                answer += tmp;
                tmp = 0;
            }
            else tmp++;
            i++;
        }
        return answer;
    }

    int trap(vector<int>& height) {
        int answer = 0, base = 0;
        int z = *max_element(height.begin(), height.end());
        while(z--) {
            answer += count(height, base);
            base++;
        }
        return answer;
    }
};

// Solution 2: O(n) time, O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0, n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        for(int i = 0; i < n; i++) {
            if(min(rightMax[i], leftMax[i]) - height[i] > 0) {
                answer += min(rightMax[i], leftMax[i]) - height[i];
            }
        }
               
        return answer;
    } 
};

// Solution 3: O(n) time, O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0, n = height.size();
        int left = 0, right = n - 1;
        int leftMax = height[0], rightMax = height[n-1];

        while(left < right) {
            if(leftMax < rightMax) {
                left++;
                leftMax = max(height[left], leftMax);
                answer += leftMax - height[left];
            }
            else {
                right--;
                rightMax = max(height[right], rightMax);
                answer += rightMax - height[right];
            }
        }
        return answer;
    }
};
