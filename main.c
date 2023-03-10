#include <stdio.h>

void input_no(int *lotto);
void print_no(int *lotto);
int main(void ){
    int lotto_number[6];
    input_no(lotto_number);
    print_no(lotto_number);
    return 0;
}
// 3 7 15 22 35 40
void input_no(int *lotto){
    int *start = lotto;
    while (lotto < start + 6){
        int number;
        printf("enter number between 1 and 45 : ");
        scanf("%d", &number);
        if(number < 1 || number > 45){
            printf("%d is not in range.\n", number);
            continue;
        }

        int is_duplicate = 0;
        for(int i = 0; i < lotto - start; i++){
            if(number == *(start + i)){
                printf("%d is in lotto\n", number);
                is_duplicate = 1;
                continue;
            }
        }
        if(!is_duplicate){
            *lotto = number;
            lotto++;
        }
    }
}
void print_no(int *lotto) {
    printf("lotto numbers : ");
    for(int i = 0; i < 6; i++){
        printf("%-5d", *lotto++);
    }
}
