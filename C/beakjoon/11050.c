#include<stdio.h>

int factorial(int num);

int main(){
    int N, K;

    scanf("%d %d", &N, &K);

    printf("%d", factorial(N) / (factorial(N - K) * factorial(K)));
}

int factorial(int num){
    int sum = 1;

    if(num == 0)
        return 1;

    for (int i = 1; i <= num; i++)
    {
        sum *= i;
    }
    return sum;
}