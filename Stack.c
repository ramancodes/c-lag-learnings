#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1, val, i;

void push(void);
void pop(void);
void display(void);

int main()
{
    int choice;
    printf("Choose the function you want to perform\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do
    {
        printf("Enter you Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Wrong choice\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

void push()
{
    if (top >= MAX)
    {
        printf("The stack is full - Overflow\n");
    }
    else
    {
        printf("Enter the value to be entered : ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("The stack is empty - Underflow\n");
    }
    else
    {
        printf("The element to be poped is %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top < 0)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The elements of the stack are \n");
        for (i = top; i >= 0; i--) // the memory still resides there
        {
            printf("| %d |\n", stack[i]);
            printf("_____\n");
        }
        // printf("\nDeleted = %d\n", stack[top + 1]);
    }
}
