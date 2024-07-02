// programme to find the higher  precedance of the operator...
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct stack {
    char a[SIZE];
    int top;
};

void push(struct stack *, char);
char pop(struct stack *);
int precedence(char);
int is_empty(struct stack *);

int main() {
    struct stack s;
    s.top = -1;
    int i;
    char ch;

    char exp[SIZE];

    printf("Enter the Valid Expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Ensure stack is not empty before comparing precedence
            while (!is_empty(&s) && precedence(ch) <= precedence(s.a[s.top])) {
                pop(&s); // Pop operators of higher or equal precedence
            }
            push(&s, ch);
        }
    }
    
    if (!is_empty(&s)) {
        printf("Higher = %c\n", s.a[s.top]);
    } else {
        printf("No higher precedence operator found.\n");
    }

    return 0;
}

void push(struct stack *s, char ch) {
    if (s->top < SIZE - 1) {
        s->a[++s->top] = ch;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

char pop(struct stack *s) {
    if (s->top >= 0) {
        return s->a[s->top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // Assuming no other operators are considered
    }
}

int is_empty(struct stack *s) {
    return (s->top == -1);
}

