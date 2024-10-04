class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre = [nums[0]] * len(nums)
        pos = [nums[-1]] * len(nums)
        res = [0] * len(nums)

        for i in range(1, len(nums)):
            pre[i] = pre[i - 1] * nums[i]
        
        for i in range(len(nums) - 2, -1, -1):
            pos[i] = pos[i + 1] * nums[i]
            
        for i in range(len(nums)):
            res[i] = (pre[i - 1] if i - 1 >= 0 else 1) * (pos[i + 1] if i + 1 < len(nums) else 1)

        return res