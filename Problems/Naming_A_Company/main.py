from typing import List
from collections import defaultdict

class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        d = defaultdict(set)

        for i in ideas:
            d[i[0]].add(i)
        
        firstChars = list(d.keys())
        
        res = 0
        for c1 in firstChars:
            for c2 in firstChars:
                if c1 != c2:
                    cnt_1 = 0
                    for word in d[c1]:
                        if (c2 + str(word[1:len(word)])) not in d[c2]:
                            cnt_1 += 1
                    cnt_2 = 0
                    for word in d[c2]:
                        if (c1 + str(word[1:len(word)])) not in d[c1]:
                            cnt_2 += 1

                    res += cnt_1*cnt_2
        return res
    
sol = Solution()
print(sol.distinctNames(["coffee","donuts","time","toffee"]))