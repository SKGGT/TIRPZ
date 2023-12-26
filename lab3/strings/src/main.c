#include <stdio.h>
#include "strings.h"

int main(){
    int function;
    char str1[255], str2[255];
    printf("1. len\n2. join\n3. slice\n4. reverse\n5. trim\n6. prepend\n7. append\n");
    printf("Enter an operation to execute: ");
    scanf("%d", (int*)&function);
    getchar();
    switch (function)
    {
    case 1:
        printf("Enter stiring: ");
        fgets(str1, 255, stdin);
        printf("%d\n", len(str1));
        break;
    case 2:
        printf("Enter stiring 1: ");
        fgets(str1, 255, stdin);
        printf("Enter stiring 2: ");
        fgets(str2, 255, stdin);
        printf("%s\n", join(str1, str2));
        break;
    case 3:
        printf("Enter stiring: ");
        fgets(str1, 255, stdin);
        int start, end;
        printf("Enter starting index: ");
        scanf("%d", (int*)&start);
        getchar();
        printf("Enter end index:" );
        scanf("%d", (int*)&end);
        printf("%s\n", slice(str1, start, end));
        break;
    case 4:
        printf("Enter stiring: ");
        fgets(str1, 255, stdin);
        printf("%s\n", reverse(str1));
        break;
    case 5:
    printf("Enter stiring: ");
        fgets(str1, 255, stdin);
        printf("'%s'\n", trim(str1));
        break;
    case 6:
        printf("Enter stiring: ");
        fgets(str1, 255, stdin);
        printf("Enter prefix: ");
        fgets(str2, 255, stdin);
        printf("%s\n", prepend(str1, str2));
        break;
    case 7:
        printf("Enter stiring: ");
        fgets(str1, 255, stdin);
        printf("Enter postfix: ");
        fgets(str2, 255, stdin);;
        printf("%s\n", append(str1, str2));
        break;
    
    default:
        break;
    }

    return 0;
}