#include<stdio.h>
#include<stdlib.h>
#define Max 5
char cq[Max];
int front = -1 , rear = -1;
void insert(char);
void delete();
void display();
void main()
{
    int ch;
    char item ; 
    while(1)
    {
        printf("\n\n~~Main Menu ~~");
        printf("\n 1. Insert and Overflow Demo");
        printf("\n2.Delete and Underflow Demo");
        printf("\n3.Display");
        printf("\n4.Exit");;
        printf("\n Enter your choice");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : printf("Enter the element to be inserted\n");
                    scanf("%c", item);
                    insert(item);
                    break;
            case 2 : delete();
                    break;
            case 3 : display();
                    break;
            case 4 : exit(0);
            default : printf("Invalid Choice");
        }
    }
}
void insert(char item)
{
    if (front == (rear+1)%Max)
    {
        printf("\n\n~~ Circular Queue Overflow");
    }
    else
    {
        if(front == -1)
            front = rear = 0;
        else
            rear = (rear +1)%Max;
    }
    cq[rear]=item;
}
void delete()
{
    char item ; 
    if (front == -1)
    {
        printf("~~Circular Queue Underflow~~");
    }
    else 
    {
        item = cq[front];
        printf("]n Delted  element from the queue is %c", item );
        if (front == rear)
            front = rear = -1;
        else 
            front = (front+1)%Max;
    }
}
void display()
{
    int i; 
    if (front == -1)
    {
        printf("~~Circular  Queue Underflow~~");
    }
    else
    {
        printf("\n Circular Queue elements : ");
        printf("Front[%d] ->", front);
        for(i=front; i!= rear ; i = (i+1)%Max)
        {
            printf("%c", cq[i]);
        }
        printf("%c",cq[i]);
        printf("<- [%d]Rear", rear);
    }
}