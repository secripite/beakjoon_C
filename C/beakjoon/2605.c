#include<stdio.h>

int stack1[101];
int stack2[101];
int top1 = 0;
int top2 = 0;

void push1(int num)
{
    stack1[top1] = num;
    top1++;
}

int pop1()
{
    return (stack1[--top1]);
}

void push2(int num)
{
    stack2[top2] = num;
    top2++;
}

int pop2()
{
    return (stack2[--top2]);
}

int main(){

    int cnt;
    int numbers[101]={0,};
    int temp1, temp2;

    scanf("%d", &cnt);

    for (int i = 0; i < cnt;i++){

        scanf("%d", &numbers[i]);
    }

    for (int j = 0; j < cnt;j++){
        temp1 = numbers[j];
        temp2 = temp1;
        
        while (temp1 != 0)
        {
            push2(pop1());
            temp1--;
        }
        
        push1(j+1);

        while (temp2 != 0)
        {
            push1(pop2());
            temp2--;
        }
    }

    for (int n = 0; n < top1;n++){
        printf("%d ", stack1[n]);
    }
}