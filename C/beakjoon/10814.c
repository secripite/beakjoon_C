#include <stdio.h>
#include <string.h>

#define MaxName 100

typedef struct member
{
    int old;
    int rank;
    char name[MaxName];
}members;

members list[100000];

void sort(members *list,int mem_num){
    members temp;

    for (int i = 0; i < mem_num;i++){
        for (int j = 0; j < mem_num - i - 1; j++)
        {
            if (list[j].old>list[j+1].old){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
        for (int j = 0; j < mem_num - i - 1; j++)
        {
            if (list[j].old==list[j+1].old&&list[j].rank>list[j+1].rank){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int main(){
    int N,old;
    char name[100];

    scanf("%d", &N);

    for (int i = 0; i < N;i++){
        scanf("%d", &old);
        scanf("%s", name);
        list[i].old = old;
        strcpy(list[i].name, name);
        list[i].rank = i;
    }
    sort(list, N);

    for (int i = 0; i < N; i++){
        printf("%d %s\n", list[i].old, list[i].name);

    }
}   