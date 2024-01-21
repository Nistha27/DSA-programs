#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[25],name[25],branch[25];
int sem;
long int phone;
struct node *link;
};
typedef struct node *NODE;
NODE start = NULL;
int count = 0;
NODE create()
{
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));
    if(snode == NULL)
    {
        printf("\n Memory Insufficient\n");
        exit(0);
    }
    printf("\n Enter the usn, Name , Branch , sem , Phone NO of the student \n");
    scanf("%s%s%s%d%ld", snode->usn, snode->name,snode->branch,&snode->sem,&snode->phone);
    snode -> link = NULL;
    count ++;
    return snode;
}


NODE insert_front()
{
    NODE temp;
    temp = create();
    if(start == NULL)
    {
        return temp;
    }
    temp -> link = start;
    return temp;

}
NODE delete_front()
{
    NODE temp;
    if(start==NULL)
    {
        printf("Linked List empty\n");
        return NULL;
    }
    if(start->link ==NULL)
    {
        printf("Element deleted of usn = %s\n", start -> usn);
        free(start);
        count--;
        return NULL;
    }
    temp = start;
    start = start -> link;
    printf("Node deleted of usn = %s\n" ,temp->usn);
    count --;
    free(temp);
    return start;
}
NODE insert_end()
{
    NODE cur , temp ;
    temp = create();
    if(start == NULL)
    {
        return temp;
    
    }
    cur = start;
    while(cur->link != NULL)
    {
        cur = cur -> link;
    }
    cur -> link = temp;
    return start;
}
NODE delete_end()
{
    NODE cur , prev;
    prev = NULL;
    if(start == NULL)
    {
        printf("Linked List empty\n");
        return NULL;
    }
    if(start -> link == NULL)
    {
        printf("Node deleted %s ", start -> usn);
        free(start);
        return NULL;
    }
    cur = start;
    while(cur -> link != NULL)
    {
        prev = cur;
        cur = cur -> link;
    }
    prev -> link = NULL;
    printf("Node deleted of usn %s", cur -> usn);
    free(cur);
    count --;
    return start ;
}
void display()
{
    NODE cur = start;
    int num = 1, i;
    if(start == NULL)
    {
        printf("\n No contents to Display");
        return ;
    }
    printf("\n The content of SLL\n");
    while(cur!=NULL)
    {
        printf("\n |%d|\t |USN : %s|\t |Name : %s|\t |Branch : %s|\t |Sem : %d|\t |Phone no : %ld|\n", cur->usn,cur->name,cur->branch,cur->sem,cur->phone);
        cur = cur -> link;
        num ++;
    }
    printf("No fo student node %d",  count);
}
void stack_demo()
{
    int ch;
    while(1)
    {
        printf("\n~~STACK DEMO~~\n");
        printf("\n1.Push operation \n 2.Pop Operation \n 3.Display\n 4.Exit\n");
        printf("\n Enter your choice for stack demo\n");
        scanf("%d", ch);
        switch(ch)
        {
            case 1 : start = insert_front();
                        break;
            case 2 : start =  delete_front();
                        break;
            case 3 : display();
                        break;
            case 4 : exit(1);
            default : return;
        }
    }
}
int main()
{
    int ch , i , n ;
    while(1)
    {
        printf("\n~~Menu~~");
        printf("\n Enter your choice \n");
        printf("\n1.Create Sll\n");
        printf("\n2.Display Status\n");
        printf("\n3.Insert End\n");
        printf("\n4.Delete End\n");
        printf("\n5.Stack Demo\n");
        printf("\n6.Exit\n");
        printf("\n Enter your choice");
        scanf("%d",ch);
        switch(ch)
        {
            case 1 : printf("\n Enter the no of students\n");
                    scanf("%d",n);
                    for(i=0;i<n;i++)
                    {
                        start = insert_front();
                    }
                    break;
            case 2 : display();
                    break;
            case 3 : start = insert_end();
                    break;
            case 4 : start = delete_end();
                    break;
            case 5 : stack_demo();
            case 6 : exit(0);
            default : printf("\nInvalid Input");
        }

    }
}