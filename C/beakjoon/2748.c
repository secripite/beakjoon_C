#include<stdio.h>
long long memo[100];

long long fibo(int num){
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

    printf("%lld", fibo(num));
}