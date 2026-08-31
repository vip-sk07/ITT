int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(int), compare);

    int longest = 1;
    int current_streak = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            if (nums[i] == nums[i - 1] + 1) {
                current_streak++;
            } else {
                if (current_streak > longest) {
                    longest = current_streak;
                }
                current_streak = 1;
            }
        }
    }

    if (current_streak > longest) {
        longest = current_streak;
    }

    return longest;
}
