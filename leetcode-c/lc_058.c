//
// LeetCode
// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
//


int lengthOfLastWord(char* s) {
    int i, j;
    
    if ((i = strlen(s)) == 0)
        return 0;
    
    j = 0;
    while (--i >= 0) {
        if (s[i] != ' ' && i >= j)
            j = i;
        
        if (s[i] == ' ' && i <= j)
            break;
    }
    
    return j - i;
}
