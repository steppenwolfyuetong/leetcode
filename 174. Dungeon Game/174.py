class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m = len(dungeon)
        n = len(dungeon[0])
        dungeon[-1][-1] = 1 if dungeon[-1][-1] >= 0 else 1 - dungeon[-1][-1]

        #HP must be greater than 0
        for i in range(m-2, -1, -1):
            dungeon[i][-1] = max(1,dungeon[i+1][-1] - dungeon[i][-1])
        for j in range(n-2, -1, -1):
            dungeon[-1][j] = max(1,dungeon[-1][j+1] - dungeon[-1][j])
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                a = max(1,dungeon[i+1][j] - dungeon[i][j])
                b = max(1,dungeon[i][j+1] - dungeon[i][j])
                dungeon[i][j] = min(a,b)
        return dungeon[0][0]

s = Solution()
dungeon = [[-3,-12,4],[4,-2,0],[6,-7,-2]]
print(s.calculateMinimumHP(dungeon))
dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
print(s.calculateMinimumHP(dungeon))

