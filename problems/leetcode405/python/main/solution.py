class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return '0'
        hex_digits = '0123456789abcdef'
        result = ''
        if num < 0:
            num = num + 2**32
        while num != 0:
            remainder = num % 16
            result = hex_digits[remainder] + result
            num = num // 16
        return result