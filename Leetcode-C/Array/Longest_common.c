#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0 || strs == NULL) {
        char* empty = (char*)malloc(1);
        if (empty == NULL) return NULL;
        empty[0] = '\0';
        return empty;
    }

    int i = 0;
    while (strs[0][i] != '\0') {
        char ch = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != ch) {
                char* result = (char*)malloc(i + 1);
                if (result == NULL) return NULL;
                for (int k = 0; k < i; k++) {
                    result[k] = strs[0][k];
                }
                result[i] = '\0';
                return result;
            }
        }
        i++;
    }

    char* result = (char*)malloc(i + 1);
    if (result == NULL) return NULL;
    for (int k = 0; k < i; k++) {
        result[k] = strs[0][k];
    }
    result[i] = '\0';
    return result;
}
