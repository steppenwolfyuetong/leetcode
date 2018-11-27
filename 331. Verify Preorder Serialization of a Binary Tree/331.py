class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """

        # remember how many empty slots we have
        # non-null nodes occupy one slot but create two new slots
        # null nodes occupy one slot

        preorder = preorder.split(',')
        slot = 1
        for node in preorder:
            if slot == 0:
                return False

            if node == '#':
                slot -= 1
            else:
                slot += 1

        return slot == 0

if __name__ == "__main__":
    s = Solution()
    pre = "9,3,4,#,#,1,#,#,2,#,6,#,#"
    print(s.isValidSerialization(pre))
