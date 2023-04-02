class Solution:
    def addBinary(self, a: str, b: str) -> str:
        len_a = len(a)
        len_b = len(b)
        max_len = len_a
        if len_a > len_b:
            gap = len_a - len_b
            for i in range(0, gap):
                b = '0' + b
        elif len_a < len_b:
            max_len = len_b
            gap = len_b - len_a
            for i in range(0, gap):
                a = '0' + a
        temp = 0
        result = []
        a = list(a)
        b = list(b)
        a.reverse()
        b.reverse()
        for i, bit_a in enumerate(a):
            sum_bit = int(bit_a) + int(b[i]) + temp
            if sum_bit == 3:
                result.append('1')
                temp = 1
            elif sum_bit == 2:
                result.append('0')
                temp = 1
            elif sum_bit == 1:
                result.append('1')
                temp = 0
            elif sum_bit == 0:
                result.append('0')
                temp = 0
        if temp == 1:
            result.append('1')
        result.reverse()
        return ''.join(result)
