class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        area1 = (C-A) * (D-B)
        area2 = (G-E) * (H-F)

        left, right = max(A,E), min(C,G)
        top, bottom = min(D,H), max(B,F)

        overlap = 0
        if right > left and top > bottom:
            overlap = (right - left) * (top - bottom)
        return area1 + area2 - overlap

s = Solution()
print(s.computeArea(-3,0,3,4,0,-1,9,2))

