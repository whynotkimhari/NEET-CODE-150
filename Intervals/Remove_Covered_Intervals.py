class Solution(object):
    def removeCoveredIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        length = len(intervals)
        intervals.sort()

        count, pointer1, pointer2 = 0, 0, 1

        while pointer2 < length and pointer1 < length:
            
            if intervals[pointer1][0] <= intervals[pointer2][0] and intervals[pointer2][1] <= intervals[pointer1][1]:
                count += 1
                pointer2 += 1

                if pointer2 < length and intervals[pointer1] is intervals[pointer2]:
                    pointer2 += 1

            elif intervals[pointer2][0] <= intervals[pointer1][0] and intervals[pointer1][1] <= intervals[pointer2][1]:
                count += 1
                pointer1 += 1
                
                if pointer1 < length and intervals[pointer1] is intervals[pointer2]:
                    pointer1 += 1

            else:
                pointer1 = pointer2
                pointer2 += 1

        return length - count