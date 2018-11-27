class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        # 按照身高从高到低 人数从小到大的顺序排列
        people.sort(key = lambda person: (-person[0],person[1]))
        # [[7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]]
        # 按照人数的index插入到结果中即可
        rt = []
        for p in people:
            rt.insert(p[1],p)
        """
        [[7, 0]]
        [[7, 0], [7, 1]]
        [[7, 0], [6, 1], [7, 1]]
        [[5, 0], [7, 0], [6, 1], [7, 1]]
        [[5, 0], [7, 0], [5, 2], [6, 1], [7, 1]]
        [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
        """
        # Explanation:
        # 对于person = (h, k)
        # 1）对于同样身高的人，人数大的人一定排在后面
        # 2）高的人总是先插入排队，后插入的人身高一定小于等于之前插入的人
        # 3）身高较高的人计算人数时，不会计入较矮的人，因此后插入的人依次插入时并不会影响之前的排队
        # 根据以上几条，每次插入时，只需按k为索引插入，既不会影响之前排队，又保证了当前插入的person前面有k个人比他高
        return rt

if __name__ == "__main__":
    s = Solution()
    seq = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    print(s.reconstructQueue(seq))
