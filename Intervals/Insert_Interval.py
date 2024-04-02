class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        length = len(intervals)
        intervals.sort()

        q = []
        maxB, minB = intervals[0][1], intervals[0][0]

        for interval in intervals:
            if interval[1] < minB or maxB < interval[0]:
                q.append([minB, maxB])
                maxB, minB = interval[1], interval[0]
                    
            else:
                maxB = max(maxB, interval[1])
                minB = min(minB, interval[0])

        q.append([minB, maxB])
        return q
                