#include <stdbool.h>

bool isMatch(const char* s, const char* p) {
    int sIdx = 0, pIdx = 0;
    int matchIdx = 0;
    int starIdx = -1;
    
    while (s[sIdx] != '\0') {
        if (p[pIdx] != '\0' && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
            sIdx++;
            pIdx++;
        }
        else if (p[pIdx] == '*') {
            starIdx = pIdx;
            matchIdx = sIdx;
            pIdx++;
        }
        else if (starIdx != -1) {
            pIdx = starIdx + 1;
            matchIdx++;
            sIdx = matchIdx;
        }
        else {
            return false;
        }
    }
    
    while (p[pIdx] == '*') {
        pIdx++;
    }
    
    return p[pIdx] == '\0';
}

