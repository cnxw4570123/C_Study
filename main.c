#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

int comparePoint(const void *_elem1, const void *_elem2){
    Point *elm1 = (Point *) _elem1;
    Point *elm2 = (Point *) _elem2;

    if(elm1->point > elm2->point) return 1;
    else if(elm1->point < elm2->point) return -1;
    return 0;
}

int main() {
    Point *congratulation = &DataSet[14142];
    printf("정렬 전\n");
    printf("고객 아이디 : %d, 고객 포인트 : %f\n", congratulation->id, congratulation->point);
    qsort(DataSet, 30000, sizeof(Point), comparePoint);
    printf("정렬 후\n");
    printf("고객 아이디 : %d, 고객 포인트 : %f\n", congratulation->id, congratulation->point);
    return 0;
}
