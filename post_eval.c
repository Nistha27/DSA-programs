#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int s[20] , top=-1;
int evaluate(char*);
void push(int);
int pop();
void main()
{
    int res;
    char post[20];
    printf("Enter the postfix expression");
    scanf("%s",post);
    res = evaluate(post);
    printf("Result of %s = %d", post,res);
}
int evaluate(char *post)
{
    int i , op1 , op2 , res , x;
    char sym;
    for(i=0;post[i]!='\0';i++)
    {
        sym = post[i];
        if(isalpha(sym))
        {
            printf("Enter the value for %c : ", sym);
            scanf("%d",x);
            push(x);
        }
        else if(isdigit(sym))
        {
            push(sym -'0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch(sym)
            {
                case '+' : res = op1+op2;
                            break;
                case '-' : res = op1 - op2;
                            break;
                case '*' : res = op1 *op2;
                            break;
                case '/' : res = op1/op2;
                            break;
                case '^' : res = pow(op1,op2);
                            break;
                default : printf("Invalid Operator %c \n", sym);
                            exit(0);           }
        }
        push(res);
    }
    return (pop());
}
void push(int item)
{
    top++;
    s[top] = item;
}
int pop()
{
    return s[top--];
}