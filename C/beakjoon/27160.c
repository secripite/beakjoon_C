#include<stdio.h>

#define N 100000

int main(){
    int cnt, n = 0;
    int num;
    int St = 0, Ba = 0, Li = 0, Pl = 0;
    char tempA, tempW[10];


    scanf("%d", &cnt);
    scanf("%c", &tempA);
    for (int i = 0; i < cnt;i++){
        n = 0;
        while (scanf("%c",&tempA) || 1)
        {
            if(tempA == ' ')
                break;
            tempW[n] = tempA;
            n++;
        }
        scanf("%d", &num);
        scanf("%c", &tempA);
        switch (tempW[0])
        {
        case 'S':
            St += num;
            break;
        case 'B':
            Ba += num;
            break;
        case 'L':
            Li += num;
            break;
        case 'P':
            Pl += num;
            break;
        }
        
    }

    if(Ba == 5 || St == 5 || Li == 5 || Pl == 5){
        printf("YES");
    }
    else{
        printf("NO");
    }
}