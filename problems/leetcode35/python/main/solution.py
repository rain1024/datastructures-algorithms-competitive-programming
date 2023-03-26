from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        lo = 0
        hi = len(nums) - 1
        if nums[hi] < target:
            return hi + 1
        elif nums[lo] > target:
            return 0
        while True:
            mid = lo + (hi - lo) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                if nums[mid-1] < target:
                    return mid
                hi = mid
            else:
                if nums[mid+1] >= target:
                    return mid + 1
                lo = mid
