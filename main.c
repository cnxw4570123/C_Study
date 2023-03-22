#include <stdio.h>

typedef struct {
    int num;
    char name[20];
    int kor;
    int eng;
    int math;
    int total;
    int grade;
} Student;

void selection_sort(Student *arr, int size);
void swap(Student *s1, Student *s2);

int main(void) {
    Student st[5];
    for (int i = 0; i < 5; ++i) {
        char name[20];
        printf("학번 : ");
        scanf("%d", &st[i].num);
        printf("이름 : ");
        scanf("%s", st[i].name);
        printf("국어, 영어, 수학 점수 : ");
        scanf("%d%d%d", &st[i].kor, &st[i].eng, &st[i].math);
        st[i].total = st[i].kor+st[i].eng+st[i].math;
        st[i].grade = (st[i].total / 3.0 ) >= 90 ? 'A' : (st[i].total / 3.0 ) >= 80 ? 'B' : (st[i].total / 3.0 ) > 70 ? 'C' : 'F';
    }
    printf("# before sorting data...\n");
    for (int i = 0; i < 5; ++i) {
        printf("%5d\t%5s\t%5d%5d%5d%5d%5.1lf%5c\n", st[i].num, st[i].name, st[i].kor, st[i].eng, st[i].math, st[i].total, st[i].total / 3.0, st[i].grade);
    }
    printf("# after sorting data...\n");
    selection_sort(st, 5);

    for (int i = 0; i < 5; ++i) {
        printf("%5d\t%5s\t%5d%5d%5d%5d%5.1lf%5c\n", st[i].num, st[i].name, st[i].kor, st[i].eng, st[i].math, st[i].total, st[i].total / 3.0, st[i].grade);
    }
    return 0;
}

void selection_sort(Student *arr, int size){
    for (int i = 0; i < size - 1; ++i) {
        Student min = arr[i];
        int total_min = min.kor + min.eng + min.kor;
        for (int j = i+1; j < size; ++j) {
            int total_current = arr[j].kor + arr[j].eng + arr[j].math;
            if(total_current > total_min){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
void swap(Student *s1, Student *s2){
    Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
