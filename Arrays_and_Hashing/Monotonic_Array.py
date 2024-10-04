class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        asc = True
        dsc = True

        for i in range(1, len(nums)):
            asc &= (nums[i] >= nums[i - 1])
            dsc &= (nums[i] <= nums[i - 1])
        
        return asc or dsc