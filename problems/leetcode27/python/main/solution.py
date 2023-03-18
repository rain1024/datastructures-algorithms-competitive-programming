from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        end_pointer = len(nums) - 1
        for i in range(0, len(nums)):
            if nums[i] == val:
                while end_pointer >= i:
                    if nums[end_pointer] != val:
                        nums[i] = nums[end_pointer]
                        end_pointer = end_pointer - 1
                        break
                    end_pointer = end_pointer - 1
            if end_pointer < i:
                return i
        return end_pointer + 2
    
