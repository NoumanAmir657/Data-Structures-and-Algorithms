from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        # words.append(" " * (maxWidth + 1))
        res = []
        s = []
        length = 0
        for w in words:
            if (length + len(w)) <= (maxWidth - len(s)):
                s.append(w)
                length += len(w)
            else:
                if (len(s) == 1):
                    res.append(s[0] + " " * (maxWidth - length))
                else:
                    spaces = [0] * (len(s) - 1)
                    j = 0
                    for i in range(0, maxWidth - length):
                        if j == (len(s) - 1):
                            j = 0
                        spaces[j] += 1
                        j += 1
                    
                    c = ""
                    for i in range(0, len(s) - 1):
                        c += s[i] + " " * spaces[i]
                    c += s[len(s) - 1]
                    res.append(c)


                s = []
                s.append(w)
                length = len(w)


        c = ""
        for i in range(0, len(s) - 1):
            c += s[i] + " "
        c += s[len(s) - 1]
        c += " " * (maxWidth - len(c))
        res.append(c)
        return res
    
sol = Solution()
print(sol.fullJustify(['This', 'is', 'an', 'example', 'of', 'text', 'justification.'], 16))