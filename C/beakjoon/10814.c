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

void insertionSort(members *list, int mem_num) {
    int i, j;
    members key;

    for (i = 1; i < mem_num; i++) {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j].old > key.old) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        while (j >= 0 && list[j].old == key.old && list[j].rank > key.rank) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}

int main() {
    int N, old;
    char name[100];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &old);
        scanf("%s", name);
        list[i].old = old;
        strcpy(list[i].name, name);
        list[i].rank = i;
    }

    insertionSort(list, N);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", list[i].old, list[i].name);
    }

    return 0;
}
