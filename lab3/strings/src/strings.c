#include <stdio.h>
#include <stdlib.h>

const int len(const char *str){
    int index = 0;
    while(str[index++] != '\n' && index < 255);
    if (index >= 255)return -1;
    return index - 1;
}

char* join(const char *str1, const char *str2){
    int len1 = len(str1);
    int len2 = len(str2);
    int totalLen = len1 + len2;
    
    char *result = (char *)malloc((totalLen + 1) * sizeof(char));
    
    if (result == NULL) {
        // Memory allocation failed
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }

    for (int i = 0; i < len2; i++) {
        result[len1 + i] = str2[i];
    }

    result[totalLen] = '\0';

    return result;
}

char* slice(const char *str, int start, int end){
    int lenStr = len(str);
    if (start < 0) start = 0;
    if (end > lenStr) end = lenStr;
    if (start > end) return NULL;

    int newLen = end - start;
    char *result = (char *)malloc((newLen + 1) * sizeof(char));

    if (result == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < newLen; i++) {
        result[i] = str[start + i];
    }

    result[newLen] = '\0';

    return result;
}

char* reverse(const char *str){
    int lenStr = len(str);
    char *result = (char *)malloc((lenStr + 1) * sizeof(char));

    if (result == NULL) {
        // Memory allocation failed
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lenStr; i++) {
        result[i] = str[lenStr - i - 1];
    }

    result[lenStr] = '\0';

    return result;
}

char* trim(const char *str){
    int lenStr = len(str);

    int start = 0;
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n') {
        start++;
    }

    int end = lenStr - 1;
    while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }

    if (start > end) {
        return NULL;
    }

    return slice(str, start, end + 1);
}

char* prepend(const char *str, const char *prefix) {
    char *result = join(prefix, str);
    return result;
}

char* append(const char *str, const char *suffix) {
    char *result = join(str, suffix);
    return result;
}
