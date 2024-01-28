#include<stdio.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE first = NULL;
NODE create()
{
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));
    if(snode == NULL)
    {
        printf("Insufficient Memory");
        return NULL;
    }
    printf("Enter the data ");
    scanf("%d",&snode->data);
    snode->link = '\0';
    return snode;
}
NODE insert_front()
{
    NODE temp;
    temp = create();
    if(first == NULL)
    {
        return temp;
    }
    if(first->link=NULL)
    {
        temp->link = first;
        first ->link = NULL;
        return temp;
    }
    temp->link = first;
    return temp;
}
void search()
{
    int key;
    NODE cur;
    printf("Enter the key");
    scanf("%d",&key);
    cur = first;
    while(cur!=NULL)
    {
        if(cur->data == key)
        {
            printf("Key Found");
            return;
        }
        cur = cur->link;
    }
    printf("Key not found");
}

void main()
{
   int n, i;
   printf("Enter the no of nodes to be enterd");
   scanf("%d",&n); 
   for(i=0;i<n;i++)
   {
    first = insert_front();
   }
   search();
}