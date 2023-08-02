class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        vector<int> checking1, checking2;
        set<int> numSet1;
        set<int> numSet2;

        for(auto &num: nums1) numSet1.insert(num);
        for(auto &num: nums2) numSet2.insert(num);

        for(auto &num: nums1) {
            int size1 = numSet2.size();
            numSet2.insert(num);
            int size2 = numSet2.size();

            if(size1 != size2) {
                checking1.push_back(num);
            }
        }

        for(auto &num: nums2) {
            int size1 = numSet1.size();
            numSet1.insert(num);
            int size2 = numSet1.size();

            if(size1 != size2) {
                checking2.push_back(num);
            }
        }

        answer.push_back(checking1);
        answer.push_back(checking2);

        return answer;
    }
};
