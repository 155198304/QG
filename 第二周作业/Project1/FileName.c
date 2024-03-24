#include <stdio.h>#include <stdlib.h>#include <stdbool.h>#define MAX_STACK_SIZE 100typedef struct {    int* data;    int top;} Stack;void init(Stack* s) {    s->data = (int*)malloc(MAX_STACK_SIZE * sizeof(int));    if (s->data == NULL) {        printf("Error: unable to allocate memory for stack.\n");        exit(EXIT_FAILURE);    }    s->top = -1;}bool isEmpty(Stack s) {    return s.top == -1;}void push(Stack* s, int value) {    if (s->top >= MAX_STACK_SIZE - 1) {        printf("Error: stack overflow.\n");        exit(EXIT_FAILURE);    }    s->data[++(s->top)] = value;}int pop(Stack* s) {    if (isEmpty(*s)) {        printf("Error: stack underflow.\n");        exit(EXIT_FAILURE);    }    return s->data[(s->top)--];}int precedence(char op) {    if (op == '+' || op == '-')        return 1;    else        return 2;}int evaluate(char expr[]) {    Stack opStack;    init(&opStack);    int i = 0;    while (expr[i]) {        if (expr[i] >= '0' && expr[i] <= '9') {            push(&opStack, expr[i] - '0');        }        else {            int b = pop(&opStack);            int a = pop(&opStack);            switch (expr[i]) {            case '+': push(&opStack, a + b); break;            case '-': push(&opStack, a - b); break;            case '*': push(&opStack, a * b); break;            case '/': push(&opStack, a / b); break;            }        }        i++;    }    return pop(&opStack);}int main() {    char expr[MAX_STACK_SIZE];    printf("Enter expression: ");    scanf("%s", expr);    printf("Result: %d\n", evaluate(expr));    return 0;}