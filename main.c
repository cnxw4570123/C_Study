#include <stdio.h>

int max_length(char *str, int size);

int main(void ){
    char str[100];
    int max = 0, value;
    while (1){
        value = max_length(str, 100);
        if(max < value) max = value;
        if(value == EOF) break;
    }
    printf("가장 긴 단어의 길이 : %d", max);
    return 0;
}

int max_length(char *str, int size){
    int ch, max = 0;
    ch = getchar();
    if(ch == EOF) return EOF;
    while(ch != '\n'){
        *str++ = ch;
        ch = getchar();
        max++;
    }
    return max;
}