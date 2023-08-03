class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> mergeVec;
        while(i < m && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                mergeVec.push_back(nums1[i]);
                i++;
            }
            else {
                mergeVec.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            mergeVec.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()) {
            mergeVec.push_back(nums2[j]);
            j++;
        }

        for(int k = 0; k < nums1.size(); k++) {
            nums1[k] = mergeVec[k];
        }
    }
};
