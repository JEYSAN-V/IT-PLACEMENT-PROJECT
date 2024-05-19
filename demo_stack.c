#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1,i;

void clear_stack()
{
	top=-1;
}

void display_stack()
{
	if(top==-1)
	printf("STACK IS EMPTY\n");
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}

void stack_menu_display()
{
	printf("\t\t\t-------------------------------------------------\n");
	printf("\t\t\t\t\tSTACK SIMULATOR\n");
	printf("\t\t\t-------------------------------------------------\n");
	printf("\nMENU\n\n");
	printf("1.PUSH\t\t2.POP\t\t3.SIZE\t\t4.CLEAR STACK\t\t5.EXIT\n\n");
   	display_stack();	
}

void isfull()
{
	if(top==MAX_SIZE-1)
	{
		system("cls");
		stack_menu_display();
		printf("\nSTACK IS FULL STACKOVER FLOW!\nPress enter to continue...\n");
		getch();	
	}
}

void push(int a)
{
	stack[++top]=a;
}

int pop()
{
	if(top==-1)
	{
		system("cls");
		stack_menu_display();
		printf("\nSTACK IS EMPTY STACKUNDER FLOW!\nPress enter to continue...\n");
		getch();
	}
	else
	return stack[top--];
}

void display_size()
{
	system("cls");
	stack_menu_display();
	printf("\nSIZE=%d\nPress enter to continue\n",top+1);
}

void stack_simulator()
{
	int choice, value;
    while (1) 
	{
    	stack_menu_display();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
            	if(top==MAX_SIZE-1)
            	{
            		isfull();
				}
				else
				{
					printf("Enter the value to push: ");
                	scanf("%d", &value);
                	push(value);
				}
                system("cls");
                break;
            case 2:
                pop();
                system("cls");
                break;
            case 3:
                display_size();
                getch();
                system("cls");
                break;
            case 4:
            	clear_stack();
            	system("cls");
            	stack_menu_display();
            	printf("\nStack elemnets are cleared!\nPress enter to continue...\n");
                getch();
                system("cls");
                break;
            case 5:
            	system("cls");
                printf("\nExiting the stack simulator.\n");
                return;    
            default:
                printf("\nInvalid choice. Please try again \nPresss enter to continue...\n");
                getch();
                system("cls");
        }
    }
}

int main()
{
	stack_simulator();
	return 0;
}
