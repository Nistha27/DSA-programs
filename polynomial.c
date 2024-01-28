#include<stdio.h>
#include<stdlib.h>
struct poly {
    int cf;
    int px;
};
typedef struct poly *poly;
poly s = NULL;
void create()
{
    int i,n;
    printf("Enter the no of terms in the polynomial");
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficient and power of x in POLY term [%d]",i+1);
        scanf("%d%d",&s->cf, &s->px);
    }
}
void print_poly(poly s,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s->cf <0)
        {
            printf("%d",s->cf);
        }
        else
        {
            printf("+%d",s->cf);
        }
        if(s->px!=0)
        {
            printf("x^%d",s->px);
        }
        print("\n"); 
    }
}