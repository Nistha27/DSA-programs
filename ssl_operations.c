#include<stdio.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE last = NULL;
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
    if(last == NULL)
    {
        return temp;
    }
    if(last->link=last)
    {
        temp->link = last;
        last ->link = temp;
        return temp;
    }
    temp->link = last;
    return temp;
}
NODE delete_end() {
    NODE cur, prev;
    if (last == NULL) {
        printf("Linked List Empty");
        return NULL;
    }
    if (last->link == last) { // Only one node in the list
        printf("Last Node deleting %d", last->data);
        free(last);
        last = NULL;
        return NULL;
    }
    cur = last->link;
    while (cur->link != last) {
        prev = cur;
        cur = cur->link;
    }
    printf("Last Node deleting %d", cur->data);
    prev->link = last->link; 
    printf("Last Node deleting %d",last ->data);// Update the link of the second-to-last node
    free(last); // Free memory of the last node
    last = prev; // Update the last pointer
    return last;
}
void display()
{
    NODE temp;
    if ( last == NULL ) /* Check for empty list */
    {
    printf("List is empty\n");
    return;
    }
    printf("Contents of the list is\n"); /* Display till we get last node */
    temp = last->link; /* Get the address of first node */
    while (temp != last) /* Traverse till the end */
    {
    printf("%d ",temp->data);
    temp = temp->link;
    }
    printf("%d\n", temp->data); /* Display last node */
}

void main()

{
   int n, i;
   printf("Enter the no of nodes to be enterd");
   scanf("%d",&n); 
   for(i=0;i<n;i++)
   {
    last = insert_front();
   }
   last = delete_end();
   display();
}