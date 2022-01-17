#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int queue[MAX], front = -1, rear = -1, val, i;

void enqueue(void);
void dequeue(void);
void display(void);

int main()
{
    int choice;
    printf("Choose the operation you want to perform in queue\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            if (choice == 4)
            {
                exit(0);
            }
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

void enqueue()
{
    if (rear > MAX)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        printf("Enter the value to be inserted\n");
        scanf("%d", &val);

        rear = rear + 1;
        queue[rear] = val;
        printf("Front = %d\n Rear = %d\n", front, rear);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The element to be deleted is %d\n", queue[front]);
        front++;
        printf("Front = %d\n Rear = %d\n", front, rear);
    }
}

void display()
{
    if (front == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The elements are \n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}