#include <stdio.h>

int main(void) {
    int ary1[4] = {1, 2, 3, 4};
    int ary2[4] = {11, 12, 13, 14};
    int ary3[5] = {21, 22, 23, 24, 25};
    int *pary[3] = {ary1, ary2, ary3};
    int row = sizeof pary / sizeof pary[0];
    int col = sizeof ary1 / sizeof ary1[0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%5d", *(*(pary+i)+ j));
        }
        printf("\n");
    }
    return 0;
}
