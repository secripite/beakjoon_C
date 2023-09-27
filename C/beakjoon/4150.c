#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char memo[10000][1001] = { 0, };
int begin_memo[10000];

void sum(int cnt){
    int temp = 0, uptemp = 0, j = 0;
    char map1[1001], map2[1001];

    printf("R U in?%d\n",cnt);

    sprintf(map1, "%01000s", memo[cnt - 1]);
    sprintf(map2, "%01000s", memo[cnt - 2]);

    printf("where U die1\n");

    printf("%s\n", map1);
    printf("%s\n", map2);

    printf("size : %d\n", sizeof(map1));
    
    for (int i = sizeof(map1) - 1; i >= 0;i--){
        temp = map1[i] - '0' + map2[i] - '0' + uptemp;
        uptemp = temp / 10;
        temp %= temp;
        memo[cnt][i] = temp + '0';
        printf("%d : %c\n", i, memo[cnt][i]);
    }

    memo[cnt][0] = uptemp + '0';
    printf("where U die2\n");

    for ( j = 0; memo[cnt][j] == '0';j++);
    printf("where U die3\n");
    
    begin_memo[cnt] = j;

    printf("!!!sum : %d , %s\n", cnt, memo[cnt]+begin_memo[cnt]);
}

void fibo(int num){

    printf("fibo : %d\n", num);

    if(memo[num][0]){
        printf("!!!111\n");
        return;
    }
    if(num<2){
        printf("!!!222\n");
        memo[num][0] = num + 48;
        return;
    }
    printf("fibo : %d\n", num);
    fibo(num - 1), fibo(num - 2);
    printf("sum : !!!!\n");
    sum(num);
    printf("sum done?\n");

    return;  
}

int main(){
    int num;

    scanf("%d", &num);
    
    fibo(num);

    printf("!! : %s", memo[num] + begin_memo[num]);
}