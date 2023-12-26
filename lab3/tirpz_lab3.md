## Національний технічний університет України<br>“Київський політехнічний інститут ім. Ігоря Сікорського”

## Факультет прикладної математики<br>Кафедра системного програмування і спеціалізованих комп’ютерних систем


# Лабораторна робота №3<br>"Юніт тести"

## КВ-11 Коротич Олександр

## Хід виконання роботи:

## 1. Створення нового проекту за допомогою ceedling.

```
$ ceedling new strings
Welcome to Ceedling!
      create  strings/project.yml

Project 'strings' created!
 - Execute 'ceedling help' from strings to view available test & build tasks
```

## 2. Створення Makefile:

```
$ cd strings/
$ cat > Makefile
all:
	gcc src/strings.c src/main.c -o strings

clean:
	rm -rf strings

test:
	ceedling test:all

test_clean:
	ceedling clean

.PHONY: all clean test test_clean
^C
```

## 3. Функції програми:


```c
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
```


## 4. Реалізація тестування:

### 1. Створення файлу тестування:

```
$ cd strings/
cat > test_strings.c
^C
```
Файл test_strings.c
```c
#include <unity.h>
#include "strings.h"

void test_len(void){
    TEST_ASSERT_EQUAL(3, len("abc\n"));
    TEST_ASSERT_EQUAL(5, len("abcde\n"));
    TEST_ASSERT_EQUAL(0, len("\n"));
}

void test_join(void){
    TEST_ASSERT_EQUAL_CHAR_ARRAY("AB", join("A\n", "B\n"), 2);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("A B", join("A \n", "B\n"), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(" B", join(" \n", "B\n"), 2);
}

void test_slice(void){
    TEST_ASSERT_EQUAL_CHAR_ARRAY("b", slice("abcd\n", 1, 2), 1);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("ab", slice("abcd\n", 0, 2), 1);
    TEST_ASSERT_EQUAL(NULL, slice("abcd\n", 3, 1));
}

void test_reverse(void){
    TEST_ASSERT_EQUAL_CHAR_ARRAY("dcba", reverse("abcd\n"), 4);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("A", reverse("A\n"), 1);
}

void test_trim(void){
    TEST_ASSERT_EQUAL_CHAR_ARRAY("abc", trim("   abc     \n"), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("abc", trim("abc\n"), 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("a a", trim("   a a     \n"), 3);
}

void test_prepend(void){
    TEST_ASSERT_EQUAL_CHAR_ARRAY("bbbAAA", prepend("AAA\n", "bbb\n"), 6);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("b b b   AAA", prepend("  AAA\n", "b b b \n"), 11);
}
void test_append(void){
    TEST_ASSERT_EQUAL_CHAR_ARRAY("AAAbbb", append("AAA\n", "bbb\n"), 6);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("AAA   b b b", append("AAA  \n", " b b b\n"), 11);
}

```

### 2. Тестування:

```
$ ceedling


Test 'test_strings.c'
---------------------
Running test_strings.out...

--------------------
OVERALL TEST SUMMARY
--------------------
TESTED:  7
PASSED:  7
FAILED:  0
IGNORED: 0
```

### 3. Чистка ceedling:

```
$ ceedling clean

Cleaning build artifacts...
(For large projects, this task may take a long time to complete)
```

### 4. Тестування з gcov:

```
$ ceedling gcov:all


Test 'test_strings.c'
---------------------
Compiling test_strings_runner.c...
Compiling test_strings.c...
Compiling unity.c...
Compiling strings.c with coverage...
Compiling cmock.c...
Linking test_strings.out...
Running test_strings.out...

--------------------------
GCOV: OVERALL TEST SUMMARY
--------------------------
TESTED:  7
PASSED:  7
FAILED:  0
IGNORED: 0


---------------------------
GCOV: CODE COVERAGE SUMMARY
---------------------------
strings.c Lines executed:92.98% of 57
strings.c Branches executed:100.00% of 42
strings.c Taken at least once:69.05% of 42
strings.c Calls executed:72.73% of 11
strings.c Lines executed:92.98% of 57

Could not find coverage results for src/main.c
```
