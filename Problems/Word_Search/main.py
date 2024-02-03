class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        firstLetter = word[0]
        position = []
        for r in range(len(board)):
            for c in range(len(board[r])):
                if board[r][c] == firstLetter:
                    position.append((r, c))
        
        res = [False]
        def dfs(newBoard, position, pointer):
            if pointer >= len(word):
                res[0] = True
                return
            r, c = position

            if (r - 1) >= 0 and newBoard[r-1][c] != '?' and board[r-1][c] == word[pointer]:
                tmp = newBoard[r-1][c] 
                newBoard[r-1][c] = '?'
                dfs(newBoard, (r-1, c), pointer + 1)
                newBoard[r-1][c] = tmp
            if (r + 1) < len(board) and newBoard[r+1][c] != '?' and board[r+1][c] == word[pointer]:
                tmp = newBoard[r+1][c] 
                newBoard[r+1][c] = '?'
                dfs(newBoard, (r+1, c), pointer + 1)
                newBoard[r+1][c] = tmp
            if (c - 1) >= 0 and newBoard[r][c-1] != '?' and board[r][c-1] == word[pointer]:
                tmp = newBoard[r][c-1] 
                newBoard[r][c-1] = '?'
                dfs(newBoard, (r, c-1), pointer + 1)
                newBoard[r][c-1] = tmp
            if (c + 1) < len(board[0]) and newBoard[r][c+1] != '?' and board[r][c+1] == word[pointer]:
                tmp = newBoard[r][c+1] 
                newBoard[r][c+1] = '?'
                dfs(newBoard, (r, c+1), pointer + 1)
                newBoard[r][c+1] = tmp

        for p in position:
            if not res[0]:
                newBoard = copy.deepcopy(board)
                newBoard[p[0]][p[1]] = '?'
                dfs(newBoard, p, 1)
            else:
                break
        return res[0]
