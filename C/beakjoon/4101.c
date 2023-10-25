#include <stdio.h>

int main(){
    int A,B;

    do{
        scanf("%d %d", &A, &B);
        if(A == 0 && B == 0)
            break;
        if(A>B){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    } while (1);
}