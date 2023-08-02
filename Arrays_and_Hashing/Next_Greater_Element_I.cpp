class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        vector<int> answer;

        for(int i = 0; i < nums2.size(); i++) {
            m[nums2[i]] = i; 
        }

        for(auto &num : nums1) {
            int took = -1;
            for(int i = m[num] + 1; i < nums2.size(); i++) {
                if(nums2[i] > num && nums2[i] > took) {
                    took = nums2[i];
                    break;
                }
            }
            answer.push_back(took);
        }

        return answer;
    }
};
