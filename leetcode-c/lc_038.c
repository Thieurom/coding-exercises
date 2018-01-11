//
// LeetCode
// 38. Count and Say
// https://leetcode.com/problems/count-and-say/
//


char* countAndSay(int n) {
    int i, j, l, count;
    char num, *s, *result;
    
    if (n == 1)
        return "1";
    
    s = countAndSay(n - 1);
    l = strlen(s);
    result = (char *) malloc((2*l + 1) * sizeof(char));
    num = s[0];
    count = 1;
    j = 0;
    
    for (i = 1; i < l; i++) {
        if (s[i] == num) {
            count++;
        } else {
            result[j++] = '0' + count;
            result[j++] = num;

            count = 1;
            num = s[i];
        }
    }
    
    result[j++] = '0' + count;
    result[j++] = num;
    result[j] = '\0';
    
    return result;
}
