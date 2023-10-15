#include<stdio.h>
#define N 25
#define L 25

char stack[N][L];
int top = 0;

void push(char *word){
    int i = 0;

    while(word[i] != ' '){
        stack[top][i] = word[i];
        i++;
    }
    stack[top][i] = '\0';
    top++;
}

char* pop(){
    return (stack[--top]);
}

int main(){
    int cnt, prtCnt = 1;
    int n = 0, m = 0;
    char tempA;
    char temp[L];

    scanf("%d", &cnt);
    scanf("%c", &tempA);

    for (int i = 0; i < cnt;i++){
        n = 0;
        while (scanf("%c",&tempA) != '\n')
        {
            if(tempA == ' '){
                temp[n] = ' ';
                push(temp);
                n = 0;
                continue;
            }
            else if(tempA == '\n'){
                temp[n] = ' ';
                push(temp);
                break;
            }
            temp[n] = tempA;
            n++;

        }

        printf("Case #%d: ", prtCnt);
        prtCnt++;
        while(top != 0){
            printf("%s ", pop());
        }
        printf("\n");
    }
}