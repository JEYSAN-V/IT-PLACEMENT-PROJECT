#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int circular_queue[MAX_SIZE];
int front = -1;
int rear = -1;

void clear_queue() 
{
    front = -1;
    rear = -1;
}

void display_queue() 
{
    if (front == -1) 
    {
        printf("QUEUE IS EMPTY\n");
    } 
    else 
    {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) 
        {
            printf("%d->", circular_queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", circular_queue[rear]);
    }
}

void queue_menu_display() 
{
    printf("\t\t\t-------------------------------------------------\n");
    printf("\t\t\t\t\t QUEUE SIMULATOR\n");
    printf("\t\t\t-------------------------------------------------\n");
    printf("\nMENU\n\n");
    printf("1.ENQUEUE\t\t2.DEQUEUE\t\t3.SIZE\t\t4.CLEAR QUEUE\t\t5.EXIT\n\n");
    display_queue();
}

void is_full() 
{
    if ((rear + 1) % MAX_SIZE == front) 
	{
        system("cls");
        queue_menu_display();
        printf("\nQUEUE IS FULL (QUEUE OVERFLOW!)\nPress enter to continue...\n");
        getch();
    }
}

void enqueue(int value) 
{
    if (front == -1) 
	{
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    circular_queue[rear] = value;
}

int dequeue() 
{
    if (front == -1) 
	{
        system("cls");
        queue_menu_display();
        printf("\nQUEUE IS EMPTY (QUEUE UNDERFLOW!)\nPress enter to continue...\n");
        getch();
        return -1; // Return a sentinel value to indicate underflow
    } 
	else 
	{
        int dequeued_value = circular_queue[front];
        if (front == rear) 
		{
            // Only one element in the queue
            front = -1;
            rear = -1;
        }
		else 
		{
            front = (front + 1) % MAX_SIZE;
        }
        return dequeued_value;
    }
}

void display_queue_size() 
{
    system("cls");
    queue_menu_display();
    int size = (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    printf("\nSIZE = %d\nPress enter to continue\n", size);
    getch();
}

void queue_simulator() 
{
    int choice, value;
    while (1) 
	{
        queue_menu_display();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                if ((rear + 1) % MAX_SIZE == front) 
				{
                    is_full();
                } else 
				{
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                }
                system("cls");
                break;
            case 2:
                dequeue();
                system("cls");
                break;
            case 3:
                display_queue_size();
                system("cls");
                break;
            case 4:
                clear_queue();
                system("cls");
                queue_menu_display();
                printf("\nQueue elements are cleared!\nPress enter to continue...\n");
                getch();
                system("cls");
                break;
            case 5:
                system("cls");
                printf("\nExiting the circular queue simulator.\n");
                return;
            default:
                printf("\nInvalid choice. Please try again.\nPress enter to continue...\n");
                getch();
                system("cls");
        }
    }
}

int main() 
{
    queue_simulator();
    return 0;
}

