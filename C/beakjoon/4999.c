#include <stdio.h>

int main(){
    int cnt1 = 0, cnt2 = 0;
    char word;

    while ((word = getchar()) != '\n')
    {
        cnt1++;
    }
    while ((word = getchar()) != '\n')
    {
        cnt2++;
    }

    if(cnt1 >= cnt2){
        printf("go");
    }
    else{
        printf("no");
    }
}