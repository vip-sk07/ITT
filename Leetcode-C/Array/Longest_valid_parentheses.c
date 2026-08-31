int longestValidParentheses(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (len == 0) {
        return 0;
    }

    int* stack = (int*)malloc((len + 1) * sizeof(int));
    if (stack == NULL) {
        return 0;
    }

    int top = 0;
    stack[top] = -1;
    int max_length = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            top++;
            stack[top] = i;
        } else {
            top--;
            if (top < 0) {
                top++;
                stack[top] = i;
            } else {
                int current_length = i - stack[top];
                if (current_length > max_length) {
                    max_length = current_length;
                }
            }
        }
    }

    free(stack);
    return max_length;
}
