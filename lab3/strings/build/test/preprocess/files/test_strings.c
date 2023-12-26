#include "src/strings.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void test_len(void){

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((len("abc\n"))), (

   ((void *)0)

   ), (UNITY_UINT)(5), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((len("abcde\n"))), (

   ((void *)0)

   ), (UNITY_UINT)(6), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((len("\n"))), (

   ((void *)0)

   ), (UNITY_UINT)(7), UNITY_DISPLAY_STYLE_INT);

}



void test_join(void){

    UnityAssertEqualIntArray(( const void*)(("AB")), ( const void*)((join("A\n", "B\n"))), (UNITY_UINT32)((2)), (

   ((void *)0)

   ), (UNITY_UINT)(11), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("A B")), ( const void*)((join("A \n", "B\n"))), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(12), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)((" B")), ( const void*)((join(" \n", "B\n"))), (UNITY_UINT32)((2)), (

   ((void *)0)

   ), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

}



void test_slice(void){

    UnityAssertEqualIntArray(( const void*)(("b")), ( const void*)((slice("abcd\n", 1, 2))), (UNITY_UINT32)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("ab")), ( const void*)((slice("abcd\n", 0, 2))), (UNITY_UINT32)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((slice("abcd\n", 3, 1))), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}



void test_reverse(void){

    UnityAssertEqualIntArray(( const void*)(("dcba")), ( const void*)((reverse("abcd\n"))), (UNITY_UINT32)((4)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("A")), ( const void*)((reverse("A\n"))), (UNITY_UINT32)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

}



void test_trim(void){

    UnityAssertEqualIntArray(( const void*)(("abc")), ( const void*)((trim("   abc     \n"))), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("abc")), ( const void*)((trim("abc\n"))), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("a a")), ( const void*)((trim("   a a     \n"))), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

}



void test_prepend(void){

    UnityAssertEqualIntArray(( const void*)(("bbbAAA")), ( const void*)((prepend("AAA\n", "bbb\n"))), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("b b b   AAA")), ( const void*)((prepend("  AAA\n", "b b b \n"))), (UNITY_UINT32)((11)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

}

void test_append(void){

    UnityAssertEqualIntArray(( const void*)(("AAAbbb")), ( const void*)((append("AAA\n", "bbb\n"))), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualIntArray(( const void*)(("AAA   b b b")), ( const void*)((append("AAA  \n", " b b b\n"))), (UNITY_UINT32)((11)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

}
