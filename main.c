#include <stdio.h>

void print_binary(int *ch, int num);

int main(void ){
    int bin[32] = {0};
    int character;
    scanf("%c", &character);
    print_binary(bin, character);
    printf("%d\n", (char)character);
    return 0;
}

void print_binary(int *ch, int num) {
    int *last_bit = ch + 31;
    while(num > 2){
        *(last_bit--) = num % 2;
        num /= 2;
    }
    *last_bit = num % 2;
    *(last_bit - 1) = num / 2;
    for(int i = 0; i < 32; i++){
        printf("%u", *(ch + i));
        if((i+1) % 8 == 0) printf(" ");
    }
    printf("\n");
}

