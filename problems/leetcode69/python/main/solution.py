class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0
        high = x
        while True:
            mid = low + (high - low) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                if (mid+1)*(mid+1)>x:
                    return mid
                if (mid+1)*(mid+1)==x:
                    return mid+1
                low = mid
            else:
                high = mid