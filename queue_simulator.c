#include <stdio.h>
#include <stdlib.h>

struct node 
{
	char *name[100];
    int priority;
    struct node* next;
};

struct node* start = NULL;

void table()
{
    printf("\n\n\t\tPlease Refer this Table for your PASS!\n");
    printf("1.ELITE PASS\n");
    printf("2.GOLD PASS\n");
    printf("3.SILVER PASS\n");
    printf("4.GENERAL PASS\n");
}


struct node* insert(struct node* start) 
{	
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter YOUR NAME Name:");
    scanf(" %s",ptr-> name);
    table();
    printf("\nEnter the PASS :");
    
    scanf("%d", &ptr->priority);

    if (start == NULL || ptr->priority < start->priority) 
	{
        ptr->next = start;
        start = ptr;
    } 
	else 
	{
        struct node* p = start;
        while (p->next != NULL && p->next->priority <= ptr->priority) 
		{
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}



struct node *delete(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n NO ONE IN THE QUEUE");
    }
    else
    {
        ptr= start;
        printf("%s is MOVED out",ptr->name);
        start=start->next;
        free(ptr);
    }
    printf("\n\n\n\n\npress enter to continue...");
    getch();
    return start;
};

char* PASS(int p)
{
	switch(p)
	{
		case 1:
			return "ELITE PASS";
		case 2:
			return "GOLD PASS";
		case 3:
			return "SILVER PASS";
		case 4:
			return "GENERAL PASS";
	}
}

void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("\nTHERE ARE NO PERRSONS IN THE QUEUE");
    else
    {
        printf("\nPERSONS IN THE QUEUE ARE:\n\n");
        int i=1;
        while(ptr!=NULL)
        {
        	printf("------------------------\n");
            printf("%d->%s[%s]\n",i++,ptr->name,PASS(ptr->priority));
            ptr=ptr->next;
        }
        printf("------------------------\n");
    }
    printf("\n\n\n\n\npress enter to continue...");
    getchar();
}



int main() 
{
    int option;
    do{
        printf("\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t WELCOME to AMUSEMENT PARK!\n");
        printf("\t\t\t-----------------------------------------\n");
        printf("1.ADD A PERSON IN A QUEUE\n");
        printf("2.MOVE THE FIRST PERSON IN QUEUE\n");
        printf("3.SHOW THE PERSONS IN THE QUEUE\n");
        printf("4.EXIT\n\n");
        printf("Enter your choice:");
        scanf("%d",&option);
    switch(option)
    {
    case 1:
        start= insert(start);
        getchar();
        system("cls");
        break;
    case 2:
        start= delete(start);
        getchar();
        system("cls");
        break;
    case 3:
        display(start);
        getchar();
        system("cls");
        break;
    case 4:
    	system("cls");
    	printf("Exiting the program...\n\nPrsee enter to close...");
    	getch();
        return 0;
        break;
    default :
    	printf("invalid choice try again");
    	getch();
    	system("cls");
    }
	}while(option!=4);
    return 0;
}

