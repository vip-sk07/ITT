char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 1) return "";

    int start = 0, max_len = 0;

    for (int i = 0; i < len; i++) {
        int l1 = i, r1 = i;
        while (l1 >= 0 && r1 < len && s[l1] == s[r1]) {
            l1--;
            r1++;
        }
        int len1 = r1 - l1 - 1;

        int l2 = i, r2 = i + 1;
        while (l2 >= 0 && r2 < len && s[l2] == s[r2]) {
            l2--;
            r2++;
        }
        int len2 = r2 - l2 - 1;

        int curr_max = (len1 > len2) ? len1 : len2;
        if (curr_max > max_len) {
            max_len = curr_max;
            start = i - (curr_max - 1) / 2;
        }
    }

    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
}
