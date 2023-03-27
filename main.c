#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct arr_stack{
    int capacity;
    int top;
    int *nodes;
}Stack;

int empty(Stack *stack){
    return stack->top < 0; // 비었으면 1, 아니면 0
}

int top(Stack *stack){
    if(stack->top == -1) return -1;
    return stack->nodes[stack->top];
}

int size(Stack *stack){
    return stack->top + 1;
}

void push(Stack *stack, int x){
    if(stack->top < stack->capacity){
        stack->top++;
        stack->nodes[stack->top] = x;
    }
}

int pop(Stack *stack){
    if(stack->top > -1)
        return stack->nodes[stack->top--];
    return -1;
}

void create_stack(Stack **stack, int capacity){
    *stack = (Stack *) malloc(sizeof(Stack));
    (*stack)->nodes = (int *) malloc(sizeof(int) * capacity);
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}

int main(){
    Stack *stack = NULL;
    int n;
    scanf("%d", &n);
    scanf("%*c");
    create_stack(&stack, n);
    char command[20];
    while (n > 0){
        n--;
        fgets(command, sizeof command, stdin);
        command[strlen(command) - 1] = '\0';
        if(strcmp(command, "top") == 0){
            printf("%d\n", top(stack));
        } else if(strcmp(command, "empty") == 0){
            printf("%d\n",empty(stack));
        } else if(strcmp(command, "size") == 0){
            printf("%d\n",size(stack));
        } else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop(stack));
        } else{
            //push x
            char *num = command + 5;
            push(stack, atoi(num));
        }
    }

    return 0;
}