class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        multiple = 1
        while multiple <= n:
            multiple = multiple * 2
            if multiple == n:
                return True
            elif multiple > n:
                return False