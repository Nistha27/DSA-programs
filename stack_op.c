#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max 5
int stack[max];
int top = -1;
void push(int value)
{
    if(top>=max)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top]=value;
        printf("Pushed %d into stack\n", value);
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Empty");
        return -1;

    }
    else
    {
        return (stack[top--]);
    }
}
bool ispalindrome(char str[])
{
    int length = strlen(str);
    int i ;
    for(i=0;i<length/2;i++)
    {
        push(str[i]);
    }
    for(i=(length+1)/2 ; i<length; i++)
    {
        if(str[i]!=pop())    
        {
            return false;
        }
    }
    return true;
}
void display()
{
    int i;
     if(top==-1)
     {
        printf("Stack Empty");
     }
     else
     {
        printf("Stack Elements \n");
        for(i=0;i<=top;i++)
        {
            printf("%d",stack[i]);

        }
        printf("\n");
     }
}
int main()
{
    int choice , element;
    char str[100];
    while(1)
    {
        printf("/n Stack Operations Menu");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Check Palindrome\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your chooice");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the elment to push ");
                    scanf("%d",element);
                    push(element);
                    break;
            case 2: element =pop();
                    printf("Element deleted %d", element);
                    break;
            case 3: printf("Enter a sring\n");
                    scanf("%s",str);
                    if (ispalindrome(str))
                    {
                        printf("Strng Entered is palindrome\n");
                    }
                    else
                    {
                        printf("String enterd id=s not palindrome \n");
                    }
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting Program\n");
                    return 0;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}