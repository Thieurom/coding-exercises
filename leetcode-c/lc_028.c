//
// LeetCode
// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/
//


int strStr(char* haystack, char* needle) {
    int i, j, m, n;
    
    if (!haystack || !needle)
        return -1;
    
    m = strlen(haystack);
    n = strlen(needle);

    for (i = 0; i <= m - n; i++) {
        for (j = 0; j < n && needle[j] == haystack[i+j]; j++)
            ;

        if (j == n)
            return i;
    }

    return -1;
}
