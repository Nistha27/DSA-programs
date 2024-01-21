#include<stdio.h>
void tower_of_hanoi(int n , char s , char a , char d)
{
    if(n==1)
    {
        printf("Move disk 1 from  %S to %d ", s,d);
        return;
    }
    tower_of_hanoi(n-1, s, d, a);
    printf("Move disk %d from %s to %s", n ,s ,d);
    tower_of_hanoi(n-1,a,s,d);
}

int main()
{
    int n ;
    printf("Enter the no of disks");
    scanf("%d", n);
    tower_of_hanoi(n,'A','B','C');
    return 0;
}