#include <stdio.h>
#define SIZE 5
int queue[5];
int front = -1;
int rear = -1;

void enqueue()
{
    int item;
    if (rear == SIZE - 1)
    {
        printf("Overflow-Queue is full.\n");
        return;
    }
    printf("Enter the element to be inserted into the queue:");
    scanf("%d", &item);
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
    printf("Item is successfully inserted.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow-Queue is empty.\n");
        return;
    }
    printf("The deleted element is: %d", queue[front++]);
    if (front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow-Queue is empty.\n");
        return;
    }
    printf("The elements are:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
