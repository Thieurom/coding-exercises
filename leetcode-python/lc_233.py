class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 0:
            return 0
        
        m = n
        sum = 0
        e = 1
        while n > 0:
            r = n % 10
            n //= 10
            if r == 0:
                sum += n * e
            elif r > 1:
                sum += (n + 1) * e
            else: # r == 1
                sum += m - n * 9 * e - e + 1
                
            e *= 10
            
        return sum
