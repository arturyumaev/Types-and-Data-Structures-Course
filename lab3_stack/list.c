/* Вариант 12 Юмаев Артур */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 10
#define STACK_OVERFLOW -100

typedef struct {                    /* Основная структура */
    int max_str_sz;                 /* Максимальная длина строки */
    int size;                       /* Размер стэка */
    char* _stack[STACK_MAX_SIZE];   /* Массив слов статический */
} Stack;

void push(Stack* stack, char* str)
{
    if (stack->size >= STACK_MAX_SIZE)
    {
        printf("Stack Overflow Error\n");
        exit(STACK_OVERFLOW);
    }

    stack->_stack[stack->size] = str;
    stack->size++;
}

void print_stack(Stack* stack)
{
    printf("\nSTACK HEADER:\n");
    printf("\tCurrent free space: %d\n", STACK_MAX_SIZE - stack->size);
    printf("\tMax stack size: %d\n", STACK_MAX_SIZE);
    printf("\n\t i:     Address    \tString\n\n");
    
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        printf("\t%2d: %p\t%s\n", STACK_MAX_SIZE - i - 1, stack->_stack + i, *(stack->_stack + i));
    }
    printf("\t^\n\thead of stack\n");
}

void pop(Stack* stack)
{
    //char* null = (char*) malloc(stack->max_str_sz);
    //strcpy(null, " ");
    //push(stack, null);
    strcpy(stack->_stack[stack->size - 1], "");
    stack->size -= 1;
}

void read_and_push(Stack* stack)
{
    char* str = malloc(stack->max_str_sz);
    printf("Введите строку >> ");
    scanf("%s", str);
    push(stack, str);
}

void menu(Stack* stack)
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
                print_stack(stack);
                break;
            case 2:          
                read_and_push(stack);
                break;
            case 3:
                pop(stack);
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
    /*
    указатель:
        указатель0  : 21 байт
        указатель1  : 21 байт
        ...
        указательN-1: 21 байт
    */

    setbuf(stdout, NULL);

    // Инициализируем параметры стэка
    Stack stack;
    stack.max_str_sz = 20 + 1;
    stack.size = 0;

    // Внимание, костыль! Очищаем стэк, заполняем его пустышками
    char* null = (char*) malloc(stack.max_str_sz);
    strcpy(null, " ");
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        push(&stack, null);
    }
    stack.size = 0;

    menu(&stack);

    print_stack(&stack);

    return 0;
}