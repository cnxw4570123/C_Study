#include <stdio.h>
#include <string.h>

int main(void ){
    char str[80];
    char str2[80];
    printf("input words : ");
    scanf("%s", str);
    strcpy(str2, str);
    if(strlen(str2) > 5){
        for (int i = 5; i < strlen(str2); i++) *(str2 + i) = '*';
    }
    printf("input words : %s, replaced words: %s\n", str, str2);
    return 0;
}
