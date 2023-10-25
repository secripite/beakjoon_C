#include <stdio.h>

int main(){
    long long sum;
    int N;
    long long temp;

    for (int i = 0; i < 3; i++){
        scanf("%d", &N);
        sum = 0;
        for (int j = 0; j < N; j++){
            scanf("%d", &temp);
            sum += temp;
        }

        if(sum == 0){
            printf("0\n");
        }
        else if(sum > 0){
            printf("+\n");
        }
        else{
            printf("-\n");
        }
    }
}