class Solution {
public:
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> ans;

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while(i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;

        if(nums.size() <= 1) return nums;

        else {
            int mid = (nums.size() - 1) / 2;
            vector<int> pre(nums.begin(), nums.begin() + mid + 1);
            vector<int> bac(nums.begin() + mid + 1, nums.end());
            ans = merge(sortArray(pre), sortArray(bac));
        }

        return ans;
    }
};
