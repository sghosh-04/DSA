#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;       
    int top;
    int capacity;
};

void init(struct Stack *s, int size) {
    s->capacity = size;
    s->top = -1;
    s->arr = (int *)malloc(size * sizeof(int));
}


void push(struct Stack *s, int x) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow! Cannot push %d\n", x);
    } else {
        s->arr[++(s->top)] = x;
    }
}


int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}


void freeStack(struct Stack *s) {
    free(s->arr);
}

int main() {
    int n;
    printf("Enter stack size: ");
    scanf("%d", &n);

    struct Stack s1, s2;
    init(&s1, n);
    init(&s2, n);
    
    int ele;
    printf("Enter elements:");
    for(int i=0; i<n; i++){
        scanf("%d", &ele);
        push(&s1, ele);
    }
    
    printf("Original Stack (s1):\n");
    display(&s1);

    
    while (s1.top != -1) {
        int val = pop(&s1);
        push(&s2, val);
    }

    printf("After transferring:\n");
    printf("Stack s1: ");
    display(&s1);
    printf("Stack s2: ");
    display(&s2);

    freeStack(&s1);
    
    printf("%d", pop(&s2));

    return 0;
}
