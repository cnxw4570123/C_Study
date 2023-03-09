#include <stdio.h>

void swap(double *pa, double *pb);
void line_up(double *a, double *b, double *c);
int main() {
    double max, mid, min;
    printf("Enter three real number values : ");
    scanf("%lf%lf%lf", &max, &mid, &min);
    line_up(&max, &mid, &min);
    printf("Output sorted values : %.1lf, %.1lf, %.1lf\n", max, mid, min);
    return 0;
}


void swap(double *pa, double *pb){
    double temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void line_up(double *a, double *b, double *c){
    if(*a < *b) swap(a, b);
    if(*b < *c) swap(b, c);
    if(*a < *b) swap(a, b);
}