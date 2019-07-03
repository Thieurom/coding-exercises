def rotate(nums, k):
    """
    Do not return anything, modify nums in-place instead.
    """
    if len(nums) < 2 or k < 1: return

    k = k % len(nums)
    nums[:] = nums[-k:] + nums[:-k]
