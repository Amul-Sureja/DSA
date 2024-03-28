#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
int queue[maxsize];
int front = -1;
int rear = -1;
void enqueue()
{
    int item;
    if ((front == 0 && rear == maxsize - 1) || (rear == (front - 1) % (maxsize - 1)))
    {
        printf("overflow\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == maxsize - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % maxsize;
    }
    printf("Enter the element in enqueue: ");
    scanf("%d", &item);
    queue[rear] = item;
}
void dequeue()
{
    if (front == -1)
    {
        printf("underflow\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == maxsize - 1)
    {
        front = 0;
    }
    else
    {
        front = (front + 1) % maxsize;
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Elements in the circular queue are : ");
    if (rear >= front)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (i = front; i < maxsize; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter the choise : \n");
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
            printf("exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
