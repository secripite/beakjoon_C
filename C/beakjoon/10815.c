#include <stdio.h>

int map[20000001];

int main(){
    int N, num1, M, num2;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        scanf("%d", &num1);
        map[num1 + 10000000] += 1;
    }
    scanf("%d", &M);
    for (int i = 0; i < M;i++){
        scanf("%d", &num2);
        if(map[num2 + 10000000])
            printf("1 ");
        else
            printf("0 ");
    }
}