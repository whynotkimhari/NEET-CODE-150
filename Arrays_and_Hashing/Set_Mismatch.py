class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        d = {}
        N = len(nums)
        id = None
        for i, n in enumerate(nums):
            if n in d:
                id = i
            else:
                d[n] = 1
        for i in range(1, N+1):
            if i not in d:
                return [nums[id], i]
        return []