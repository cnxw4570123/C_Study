#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, num;
    scanf("%d", &n);
    int *data = (int *) calloc(n, sizeof(int));

    int cnt = 0;
    while (cnt < n) {
        scanf("%d", &num);
        for (int i = 0; i < cnt; ++i) {
            if (num < data[i]) {
                memmove(&data[i + 1], &data[i], sizeof(int) * (cnt - i));
                data[i] = num;
                break;
            }
        }
        if(data[cnt] == 0) data[cnt] = num;
        cnt++;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", *(data + i));
    }
    return 0;
}
