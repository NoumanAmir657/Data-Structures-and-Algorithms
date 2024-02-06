class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []

        def dfs(row, current):
            if row >= n:
                res.append(current.copy())
                return
            
            for column in range(n):
                size = len(current)
                onLineOfAttack =  False
                for i in range(size):
                    if current[i][0] == row or current[i][1] == column or abs(row-current[i][0]) == abs(column-current[i][1]):
                        onLineOfAttack = True
                        break
                
                if not onLineOfAttack:
                    current.append((row, column))
                    dfs(row + 1, current)
                    current.pop()
        
        dfs(0, [])

        final = [[] for _ in range(len(res))]
        for i, r in enumerate(res):
            final[i] = []
            for r in range(n):
                s = ''
                for c in range(n):
                    if (r,c) in res[i]:
                        s += 'Q'
                    else:
                        s += '.'
                final[i].append(s)

        return final

