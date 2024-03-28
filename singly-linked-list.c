#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

void creatlist()
{
    if (start == NULL)
    {
        int n;
        printf("enter number of node");
        scanf("%d", &n);
        if (n != 0)
        {
            int info;
            struct node *new;
            struct node *temp;
            new = malloc(sizeof(struct node));
            start = new;
            temp = start;
            printf("enter the to be insert of start node :");
            scanf("%d", &info);
            start->data = info;
            for (int i = 1; i < n; i++)
            {
                new = malloc(sizeof(struct node));
                temp->link = new;
                printf("enter the data to be indend");
                scanf("%d", &info);
                new->data = info;
                new->link = NULL;
                temp = temp->link;
            }
        }
        printf("List created");
    }
    else
        printf("List already exists");
}

void insertfirst()
{
    int info;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("enter node to be inserted : ");
    scanf("%d", &info);
    temp->data = info;
    temp->link = start;
    start = temp;
}

void inseartend()
{
    int info;
    struct node *temp, *temp2;
    temp = malloc(sizeof(struct node));
    printf("enter node to be insert :");
    scanf("%d", &info);
    temp->data = info;
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    temp2 = start;
    while (temp2->link != NULL)
    {
        temp2 = temp2->link;
    }
    temp2->link = temp;
}

void insatatpos()
{
    int info, pos, i = 1;
    struct node *temp, *temp2;
    temp = malloc(sizeof(struct node));
    printf("in enter the position ");
    scanf("%d", &pos);
    printf("enter data");
    scanf("%d", &info);
    temp->data = info;
    temp->link = NULL;
    temp2 = start;
    while (i < pos - 1)
    {
        temp2 = temp2->link;
        i++;
    }
    temp->link = temp2->link;
    temp2->link = temp;
}

void deletefront()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr = start;
        start = ptr->link;
        free(ptr);
    }
}

void deleteend()
{
    struct node *ptr, *ptr1;
    if (start == NULL)
    {
        printf("list is empty");
    }
    else if (start->link == NULL)
    {
        start = NULL;
        free(start);
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = NULL;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = start;
    if (ptr == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}

void main()
{
    int choice = 0;
    while (1)
    {
        printf("\n\n1.creat list\n2.inseart first\n3.inseart end\n4.inseart at position\n5.delete front\n6.delete end\n7.display\n8.Exit...");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            creatlist();
            break;

        case 2:
            insertfirst();
            break;

        case 3:
            inseartend();
            break;

        case 4:
            insatatpos();
            break;

        case 5:
            deletefront();
            break;

        case 6:
            deleteend();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Please enter valid choice..");
        }
    }
}