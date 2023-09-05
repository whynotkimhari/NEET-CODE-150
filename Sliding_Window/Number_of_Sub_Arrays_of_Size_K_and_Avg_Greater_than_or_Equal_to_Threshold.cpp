class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int counter = 0;
        int sum = 0;
        int len = arr.size();
        for(int i = 0; i < k; i++) sum += arr[i];

        for(int i = 0; i < len - k; i++) {
            if(sum / (k*1.0) >= threshold) counter++;
            sum += arr[i + k];
            sum -= arr[i];
        }

        sum = 0;
        for(int i = len - 1; i >= len - k; i--) {
            sum += arr[i];
        }

        if(sum / (k*1.0) >= threshold) counter++;
        return counter;
    }
};
