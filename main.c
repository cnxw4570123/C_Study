#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *create_node(int data){
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}

void append_node(Node **head, Node *new_node){
    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head;
        (*head)->prev = *head;
    }else{
        Node *tail = (*head)->prev;
        tail->next->prev = new_node;
        tail->next = new_node;
        new_node->next = *head;
        new_node->prev = tail;
    }
}

void delete_node(Node **head, Node *remove){
    if (*head == remove) {
        if ((*head)->next != *head) {
            *head = (*head)->next;
        }
    }
    remove->prev->next = remove->next;
    remove->next->prev = remove->prev;
    remove->next = NULL;
    remove->prev = NULL;
}

Node *get_node_at(Node *start, int count){
    Node *current = start;
    for (int i = 0; i < count; ++i) {
        current = current ->next;
    }
    return current;
}

int main(void){
    Node *list = NULL;
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    for (int i = 0; i < n; ++i) {
        append_node(&list, create_node(i + 1));
    }
    Node *start = list;
    printf("<");
    while (start->next != NULL) {
        Node *del = get_node_at(start, k);
        int data = del->data;
        start = del->next;
        delete_node(&list, del);
        if (start->next == NULL) printf("%d", data);
        else {
            printf("%d, ", data);
            free(del);
        }
    }
    free(list);
    printf(">");
    return 0;
}
