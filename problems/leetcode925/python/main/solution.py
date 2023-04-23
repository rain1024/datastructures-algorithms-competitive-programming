class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        j = 0
        for i in range(len(typed)):
            if j < len(name) and name[j] == typed[i]:
                j += 1
            elif i == 0 or typed[i] != typed[i-1]:
                return False
        return j == len(name)