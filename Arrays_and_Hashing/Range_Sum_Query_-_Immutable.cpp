class NumArray {
private:
    vector<int> ns;
public:
    NumArray(vector<int>& nums) {
        this->ns = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += this->ns[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
