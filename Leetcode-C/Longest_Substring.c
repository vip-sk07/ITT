int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool hasDuplicate = false;
            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    hasDuplicate = true;
                    break;
                }
            }
            if (!hasDuplicate) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            } else {
                break;
            }
        }
    }

    return maxLength;
}
