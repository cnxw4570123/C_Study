#include <stdio.h>

int main(void) {
    int rect[5][6] = {0};
    int total, *pr;

    for (int i = 0; i < 4; i++) {
        total = 0, pr = rect[i];
        for (int j = 0; j < 5; j++) {
            rect[i][j] = i*5 + j + 1;
            total += rect[i][j];
            pr++;
        }
        *pr = total;
    }

    for (int i = 0; i < 6; ++i) {
        total = 0;
        pr = *(rect + 4);
        for (int j = 0; j < 4; ++j) {
            total += rect[j][i];
        }
        *(pr + i) = total;
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("%5d", rect[i][j]);
        }
        printf("\n");
    }
    return 0;
}
