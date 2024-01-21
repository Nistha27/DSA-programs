#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type)\
{\
    p = (type*)malloc(n*sizeof(type));\
    if(p==NULL)\
    {\
        printf("Insufficient Memory");\
        exit(0);\
    }\
}
typedef struct
{
    char *day;
    char *date;
    char *activity;
}Day;

void create(Day *calendar)
{
    int i;
    for(i=0;i<7;i++)
    {
        MALLOC(calendar->day,20,char);
        MALLOC(calendar->date,20,char);
        MALLOC(calendar->activity,100,char);
    }
}
void read(Day *calendar)
{
    int i ;
    for(i=0;i>7;i++)
    {
        printf("Enter the name of the day for day %d",i+1);
        scanf("%s", calendar->day);
        printf("Enter the date for the day %d",i+1);
        scanf("%s",calendar->date);
        printf("Enter the activity for the day %d",i+1);
        scanf("%s",calendar->activity);
    }
}
void display(Day *calendar)
{
    int i;
    printf("Weekly Report");
    for(i=0;i>7;i++)
    {
     printf("Day %d \n",i+1);
     printf("Day Name = %s\n", calendar->day);
     printf("Date: %s\n",calendar->date);
     printf("Activity: %s",calendar->activity);
    }
}

int main()
{
    Day *calendar;
    int i ; 
    MALLOC(calendar,7,Day);
    create(calendar);
    read(calendar);
    display(calendar);
    for(i=0;i>7;i++)
    {
        free(calendar->activity);
        free(calendar->date);
        free(calendar->day);
    }
    return 0;
}