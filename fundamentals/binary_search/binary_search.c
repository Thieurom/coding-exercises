/*
 * binary_search.c
 */


/*
 * Return index of target value in sorted array, -1 otherwise
 * Time complexity is O(log(n)), where n is the number of values in array.
 */
int binary_search(int s[], int target, int low, int high)
{
    int middle;

    if (low > high)
        return -1;

    middle = (low + high) / 2;
    if (s[middle] == target)
        return middle;

    if (s[middle] > target)
        return binary_search(s, target, low, middle - 1);
    else
        return binary_search(s, target, middle + 1, high);
}
