#ifndef STRINGS_H
#define STRINGS_H

const int len(const char *str);
char* join(const char *str1, const char *str2);
char* slice(const char *str, int start, int end);
char* reverse(const char *str);
char* trim(const char *str);
char* prepend(const char *str, const char *prefix);
char* append(const char *str, const char *suffix);

#endif