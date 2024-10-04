class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        start = paths[0][0]

        while True:
            found = False
            for path in paths:
                if start == path[0]:
                    start = path[1]
                    found = True
            
            if not found:
                return start