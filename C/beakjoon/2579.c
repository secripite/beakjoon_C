#include <stdio.h>

int main(){
    int temp;
    int sum = 0;
    int min = 100;
    int flag = 0;

    for (int i = 0; i < 7; i++){
        scanf("%d", &temp);
        if(temp % 2 == 1){
            if(temp < min){
                min = temp;
            }
            sum += temp;
            flag = 1;
        }
    }//you are babo :)

    if(flag == 1){
        printf("%d\n", sum);
        printf("%d\n", min);
    }
    else{
        printf("-1");
    }
}