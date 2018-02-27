/* Вариант 12 Юмаев Артур */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINT(str) printf("%s\n\n", str);
#define STACK_MAX_SIZE 10
#define STACK_OVERFLOW -100

typedef struct Node {
    int size;
    char *str;
    struct Node *next;
} Node;

void push(Node **head, char* data) {

    PRINT("no segfault1");
    Node *tmp = (Node*) malloc(sizeof(Node));
    PRINT("no segfault2");
    strcpy(tmp->str, data);
    PRINT("no segfault3");
    tmp->size++;
    PRINT("no segfault4");
    tmp->next = (*head);
    PRINT("no segfault5");
    (*head) = tmp;
    PRINT("no segfault6");
}

int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
    return 0;
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
    Node *head = NULL;

    char str[] = "new";
    push(&head, str);

    return 0;
}