/* Вариант 12 Юмаев Артур */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINT(arg) printf("%s\n", arg);
#define STACK_MAX_SIZE 7
#define MAX_STR_SZ 21
#define STACK_OVERFLOW -100

typedef struct Node
{
    int size;
    char *str;
    struct Node *next;
} Node;

int push(Node **head, char* data)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    
    tmp->str = (char*) malloc(MAX_STR_SZ);    
    
    strcpy(tmp->str, data);
    
    if ((*head) == NULL)
    {
        tmp->size = 1;
    }
    else
    {
        tmp->size = (*head)->size + 1;
    }

    if ((*head) != NULL)
    {
        if ((*head)->size >= STACK_MAX_SIZE)
        {
            printf("\nStack overflow! Please, delete some elememts.\n");
            return -1;
        }
    }
    
    tmp->next = (*head);
    
    (*head) = tmp;
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

void print_stack(Node* head)
{
    int stack_size = head->size;

    printf("\nSTACK:\n(address)\t(str)\n");
    do
    {
        printf("%p\t%s\n", head->str, head->str);
        head = head->next;
    }
    while (head != NULL);

    for (int i = stack_size; i < STACK_MAX_SIZE; i++)
    {
        printf("freeAddr\tfree\n");
    }
}

void read_and_push(Node** head)
{
    char* str = (char*) malloc(MAX_STR_SZ);
    printf("Введите строку >> ");
    scanf("%s", str);
    push(head, str);
}

void menu(Node** head)
{
    int state;

    while (state != 4)
    {
        printf("\nВыберите действиe\n");
        printf("\t1.Распечатать информацию о стэке\n");
        printf("\t2.Добавить слово в стэк\n");
        printf("\t3.Удалить слово с вершины стэка\n");
        printf("\t4.Выход\n");
        printf("\t>> ");
    
        scanf("%d", &state);
            
        switch (state)
        {
            case 1:
                print_stack(*head);
                break;
            case 2:
                read_and_push(head);
                break;
            case 3:
                pop(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }   
    } 
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
    Node *head = NULL;

    push(&head, "test1");
    push(&head, "test2");
    push(&head, "test3");
    push(&head, "test4");

    menu(&head);

    return 0;
}