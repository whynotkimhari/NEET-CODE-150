class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > target) right = mid - 1;
            else if(nums[mid] < target) left = mid + 1;
            else return true;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

        vector<int> oneDmatrix;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                oneDmatrix.push_back(matrix[i][j]);
            }
        }

        return search(oneDmatrix, target);
    }
};
