class Solution:
    def largestGoodInteger(self, num: str) -> str:
        id = -1
        for i in range(0, len(num) - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                id = max(int(num[i]), id)
                i += 3
        
        return f'{id}'*3 if id != -1 else ''