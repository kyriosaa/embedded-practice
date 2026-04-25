// using stack to reverse a string
#include <stdio.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack {char s[MAX_LEN]; int top;} stack;

void reset(stack *stack) {
    stack -> top = EMPTY;
}

void push(char c, stack *stack) {
    if(stack -> top == FULL) {
        return; // stack overflow !!!!!
    }

    stack -> top++;
    stack -> s[stack -> top] = c;
}

char pop(stack *stack) {
    return(stack -> s[stack -> top--]);
}

char top(const stack *stack) {
    return(stack -> s[stack -> top]);
}

int is_empty(const stack *stack) {
    return(stack -> top == EMPTY);
}

int is_full(const stack *stack) {
    return(stack -> top == FULL);
}

int main() {
    stack   stack_of_char;
    char    *str = "i am kin am i";
    char    str_back[20];
    int     i = 0;

    reset(&stack_of_char);
    printf("Original is: %s\n", str);
    while(str[i] != '\0') {
        printf("%c\n", str[i]);
        push(str[i++], &stack_of_char);
    }
    i = 0;
    while(!is_empty(&stack_of_char) && i < 20) {
        str_back[i++] = pop(&stack_of_char);
    }
    printf("Reverse is: %s\n", str_back);
    printf("\n\n");
    return 0;
}