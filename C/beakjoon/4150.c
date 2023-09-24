/*
#include<stdio.h>
#include<stdlib.h>

char memo[100][1000];

char* fibo(int num){
    int uptmep = 0, temp, i = 0, j = 0;
    char *temp1, temp2;

    if(num == 0)
    {
        memo[num][0] = '0';
        return memo[num];
    }
    else if(num == 1){
        memo[num][0] = '1';
        return memo[num];
    }
    
    if(memo[num][0]){
        return memo[num];
    }
    else{
        temp1 = fibo(num - 1);
        temp2 = fibo(num - 2);
        while(*(*(temp1) + i) != '\0'){
            if(*(*(temp2) + j) != '\0'){
                temp = *(*(temp1) + j) + *(*(temp2) + i) - 96;
                if(temp >= 10){
                    uptemp = 1;
                }
                memo[num][i] = temp + 96;
            }
            i++, j++;
        }
    }

    return memo[num];
}

int main(){
    int num, i = 0;
    char *result;

    scanf("%d", &num);

    result = fibo(num);
    for (int i = 0; *(*(result) + i) != '\0'; i++){
        print("%c", *(*(result) + i));
    }
}
*/