class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited = set()
        visited.add((0,0))
        last = (0,0)
        for d in path:
            last = (
                last[0] + (1 if d == 'N' else (-1 if d == 'S' else 0)),
                last[1] + (1 if d == 'E' else (-1 if d == 'W' else 0))
            )
            
            if last in visited:
                return True
            
            visited.add(last)
        
        return False