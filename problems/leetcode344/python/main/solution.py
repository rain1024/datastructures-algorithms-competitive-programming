from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        len_s = len(s)
        for i in range(0, len_s//2):
            temp = s[i]
            s[i] = s[len_s - 1 - i]
            s[len_s - 1 - i] = temp