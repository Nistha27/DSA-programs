#include<stdio.h>
#include<string.h>
int in_prec(char);
int stack_prec(char);
void convert(char*,char*);
void main()
{
    char in[30],post[30];
    printf("Enter a valid infix expression\n");
    scanf("%s", in);
    convert(in,post);
    printf("Postfix expression : %s\n",post);
}
int in_prec(char sym)
{
    switch(sym)
    {
         case '+':
         case '-': return 1 ;
         case '*':
         case '/': return 3;
         case '$':
         case '^': return 6;
         case '(': return 9;
         case ')': return 0;
         default : return 7;
    }
}

int stack_prec(char sym)
{
    switch(sym)
    {
         case '+':
         case '-': return 2 ;
         case '*':
         case '/': return 4;
         case '$':
         case '^': return 5;
         case '(': return 0;
         case ')': return -1;
         default : return 8;
    }
}
void convert(char *in , char * post)
{
    char s[30], sym;
    int top = -1 , i,j=0;
    s[++top] = '#';
    for(i=0;in[i]!='\0';i++)
    {
        sym = in[i];
        while(stack_prec(s[top]) > in_prec(sym))
        {
            post[j++]= s[top--];
        }
        if(stack_prec(s[top])!=in_prec(sym))
        {
            s[++top] = sym;
        }
        else
        {
            top --;
        }
    }
    while (s[top]!='#')
    {
        post[j++]=s[top--];
    }
    post[j] = '\0';
}
    