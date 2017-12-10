//
// LeetCode
// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number
//


bool isPalindrome(int x) {
    int s;
    
    if ((x < 0) || ((x != 0) && (x % 10) == 0))
        return false;
    
    s = 0;
    while (x > s) {
        s = s * 10 + x % 10;
        x /= 10;
    }
    
    return (x == s) || (x == s / 10);
}
