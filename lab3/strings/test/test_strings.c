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