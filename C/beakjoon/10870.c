#include<stdio.h>
int memo[100];

int fibo(int num){
    if(num<2)
        return num;
    
    if(memo[num]){
        return memo[num];
    }

    memo[num] = fibo(num - 1) + fibo(num - 2);
    return memo[num];
}

int main(){
    int num;

    scanf("%d", &num);

    printf("%d", fibo(num));
}