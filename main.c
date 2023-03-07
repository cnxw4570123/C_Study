#include <stdio.h>

int main() {
    int oprnd1, oprnd2, res;
    char operator;
    printf("사칙연산 입력(정수) : ");
    scanf("%d%c%d", &oprnd1, &operator, &oprnd2);
    printf("%d %c %d = ", oprnd1, operator, oprnd2);
    switch (operator) {
        case '+':
            res = oprnd1 + oprnd2;
            break;
        case '-':
            res = oprnd1 - oprnd2;
            break;
        case '*':
            res = oprnd1 * oprnd2;
            break;
        case '/':
            res = oprnd1 / oprnd2;
            break;
        default:
            printf("입력 오류");
    }
    printf("%d", res);
    return 0;
}
