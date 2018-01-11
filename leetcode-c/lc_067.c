//
// LeetCode
// 67. Add Binary
// https://leetcode.com/problems/add-binary/
//


char* addBinary(char* a, char* b) {
    char* result;
    int size, i, j, n;
    
    i = strlen(a);
    j = strlen(b);
    size = (i > j ? i : j) + 2;
    
    if ((result = (char *) malloc(size * sizeof(char))) == NULL)
        exit(-1);
    
    result[--size] = '\0';
    i--;
    j--;
    size--;
    n = 0;
    while (size > 0) {
        if (i >= 0 && j >= 0)
            n += (a[i--] - '0') + (b[j--] - '0');
        else if (i >= 0)
            n += a[i--] - '0';
        else if (j >= 0)
            n += b[j--] - '0';
        
        result[size--] = n % 2 + '0';
        
        n = n / 2;
    }
    
    if (n > 0)
        result[size] = n % 2 + '0';
    else
        result++;
    
    return result;
}
