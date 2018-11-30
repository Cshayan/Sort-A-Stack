#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX], stackTemp[MAX];

int top1=-1, top2=-1;

void push1(int item)
{
    stack[++top1]=item;
}
void push2(int item)
{
    stackTemp[++top2]=item;
}
int pop1()
{
    return stack[top1--];
}
int pop2()
{
    return stackTemp[top2--];
}
int peek1()
{
    return stack[top1];
}
int peek2()
{
    return stackTemp[top2];
}
int isEmpty1()
{
    if(top1==-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty2()
{
    if(top2==-1)
    {
        return 1;
    }
    return 0;
}

void sortStack(int stack[])
{
    int temp;
    while(!isEmpty1())
    {
       temp=pop1();
       while(!isEmpty2() && peek2()>temp)
       {
         push1(pop2());
       }
       push2(temp);
    }
     display(stackTemp);
}
void display(int stackTemp[])
{
     printf("\n\n");
    int i=0;
    for(i=0;i<=top2;i++)
    {
        printf("%d\t", stackTemp[i]);
    }
   printf("\n\n");
}
int main()
{
    printf("\nEnter the stack size:- ");
    int n, item;
    scanf("%d", &n);
    int i;
    printf("\nEnter the stack:- ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&item);
        push1(item);
    }
    sortStack(stack);
}
