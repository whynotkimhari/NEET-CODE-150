class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int len = arr.size();

        if(x <= arr[0]) {
            for(int i = 0; i < k; i++) ans.push_back(arr[i]);
            return ans;
        }

        else if(x >= arr[len - 1]) {
            for(int i = len - k; i < len; i++) ans.push_back(arr[i]);
            return ans;
        }
        
        else {
            int diff = INT_MAX;
            int index = -1;

            for(int i = 0; i < len; i++) {
                if(diff > abs(x - arr[i])) {
                    index = i;
                    diff = abs(x - arr[i]);
                }
            }

            ans.push_back(arr[index]);
            k--;
            
            int pre = index - 1, post = index + 1;

            while(pre >= 0 && post < len && k) {
                if(abs(arr[pre] - x) <= abs(arr[post] - x)) {
                    ans.push_back(arr[pre]);
                    pre--;
                }
                else {
                    ans.push_back(arr[post]);
                    post++;
                }
                k--;
            }

            while(pre >= 0 && k) {
                ans.push_back(arr[pre]);
                pre--;
                k--;
            }

            while(post < len && k) {
                ans.push_back(arr[post]);
                post++;
                k--;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
