class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d = dict()
        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        
        rs = 0
        for key in d:
            if d[key] > 1:
                rs += (d[key]) * (d[key] - 1) // 2
            
        return rs