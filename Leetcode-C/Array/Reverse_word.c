char* reverseWords(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int i = 0;
    int j = len - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    int write_idx = 0;
    int start = 0;
    while (start < len) {
        while (start < len && s[start] == ' ') {
            start++;
        }
        if (start == len) {
            break;
        }
        if (write_idx > 0) {
            s[write_idx++] = ' ';
        }
        int end = start;
        while (end < len && s[end] != ' ') {
            end++;
        }
        int word_start = write_idx;
        while (start < end) {
            s[write_idx++] = s[start++];
        }
        int word_end = write_idx - 1;
        while (word_start < word_end) {
            char temp = s[word_start];
            s[word_start] = s[word_end];
            s[word_end] = temp;
            word_start++;
            word_end--;
        }
    }
    s[write_idx] = '\0';
    return s;
}
