//
// LeetCode
// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/
//


int mySqrt(int x) {
    int low = 1;
    int high = x;
    int guess;
    
    while (low <= high) {
        guess = low + (high - low) / 2;
        
        if (guess < x / guess)
            low = guess + 1;
        else if (guess  > x / guess)
            high = guess - 1;
        else
            return guess;
    }
    
    return high;
}
