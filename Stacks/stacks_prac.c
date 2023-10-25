#include <stdio.h>
#include <stdlib.h>
#define maxLen 10


int count = 0;


struct stack{
    int items[maxLen];
    int top;
};


typedef struct stack st;


void createEmptyStack(struct stack* Node, int data)
{
    Node->top = -1;
}


int isFull(st* Node)
{
    if(Node->top == maxLen-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int isEmpty(st* Node)
{
    if(Node->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


void push(struct stack* Node, int newItem)
{
    if(isFull(Node))
    {
        printf("FUUUULLLLLLLLLL");
    }
    else{
        Node->top++;
        Node->items[Node->top] = newItem;
    }
    count++; //to know how many items have been pushed into the stack
}


void pop(st* Node)
{
    if(isEmpty(Node))
    {
        printf("EMPTYYYYYYYYYYYY");
    }
    else
    {
        printf("Item popped = %d\n",  Node->items[Node->top]);
        Node->top--;
    }
    count--;
    printf("\n");
}

void display(struct stack* Node)
{
    printf("STACK: \n");
    for(int i = 0; i < count; i++)
    {
        printf("%d\n", Node->items[i]);
    }
    printf("\n");
    printf("Count value = %d", count);
    printf("\n");
}


int search(struct stack* Node, int data)
{
    for(int i = 0; i < count; i++)
    {
        if(Node->items[i] == data)
        {
            return i; 
        }
    }
    return -1; 
}


int main()
{
    struct stack* sk = (struct stack*)malloc(sizeof(struct stack));

    createEmptyStack(sk, 0);

    push(sk, 1);
    push(sk, 3);
    push(sk, 5);
    push(sk,7);

    display(sk);

    pop(sk);

    printf("After poppinng (da cherry): ");
    display(sk);

    int s = search(sk, 5);
    printf("Found at index: %d", s);

    return 0;
}
