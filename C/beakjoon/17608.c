#include<stdio.h>

#define N 100000
#define h 100000

int stack[N];
int top = 0;

void push(int num);
int pop();


int main(){
    int cnt, sight_cnt = 0;
    int tempH, sight_temp;
    int pop_temp;

    scanf("%d", &cnt);

    for (int i = 0; i < cnt;i++){
        scanf("%d", &tempH);
        push(tempH);
    }

    sight_temp = pop();
    sight_cnt++;

    while(top != 0){
        pop_temp = pop();
        if(pop_temp > sight_temp){
            sight_cnt++;
            sight_temp = pop_temp;
        }
    }

    printf("%d", sight_cnt);
}



void push(int num){
    stack[top] = num;
    top++;
}

int pop(){
    return stack[--top];
}