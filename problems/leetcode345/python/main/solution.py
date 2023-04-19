class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a', 'e', 'i', 'o','u']
        s = list(s)
        left = 0
        right = len(s) - 1
        while left < right:
            if s[left].lower() in vowels and s[right].lower() in vowels:
                s[left], s[right] = s[right], s[left]
                right -= 1
                left += 1
                continue
            if s[left].lower() not in vowels:
                left += 1
            if s[right].lower() not in vowels:
                right -= 1
        return ''.join(s)