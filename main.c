#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("양수 입력 : ");
    scanf("%d", &n);
    // 0 ~ n까지의 수
    int *is_not_pn = (int *) calloc(++n , sizeof(int));
    //소수면 0 , 소수가 아니면 1
    *is_not_pn = 1;
    *(is_not_pn + 1) = 1;
    // 0, 1을 제외한 2부터 n까지의 수 중 i의 배수는 소수가 x
    // i * 1 ~ (n/i)까지의 배수는 1로 초기화
    // i의 배수는 건너띄기

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= (n / i); ++j) {
            if (is_not_pn[i * j] != 0) continue;
            is_not_pn[i * j] = 1;
        }
    }

    for (int i = 2; i < n; ++i) {
        if(!is_not_pn[i]){
            printf("%5d", i);
        }else{
            printf("%5c", 'X');
        }
        if ((i - 1) % 5 == 0) {
            printf("\n");
        }
    }
    free(is_not_pn);
    return 0;
}