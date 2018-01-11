//
// LeetCode
// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
//


#define _M_ 1000
#define _D_ 500
#define _C_ 100
#define _L_ 50
#define _X_ 10
#define _V_ 5
#define _I_ 1

int romanToInt(char* s) {
    int i, n;
    int last = _M_;
    int result = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'M':
                n = _M_;
                break;
            case 'D':
                n = _D_;
                break;
            case 'C':
                n = _C_;
                break;
            case 'L':
                n = _L_;
                break;
            case 'X':
                n = _X_;
                break;
            case 'V':
                n = _V_;
                break;
            case 'I':
                n = _I_;
                break;
            default:
                return -1;
        }
        
        result += n;
        if (n > last)
            result -= 2 * last;
        
        last = n;
    }
    
    return result;
}
