#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trie_
{
    struct trie_ *num[10];
    int end;
}trie;

trie *new_trie(){
    trie *node = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 10;i++){
        node->num[i] = NULL;
    }
    node->end = 0;
    return node;
}

void insert( trie* head, char str[]){
    trie *cur = head;
    int index = 0;
    while(str[index])
    {
        int idx = str[index] - '0';
        if(cur->num[idx] == NULL){
            cur->num[idx] = new_trie();
        }
        cur = cur->num[idx];
        index += 1;
    }
    cur->end = 1;
}

int search(trie *head, char str[]){

    if(head == NULL) return 0;

    trie *cur = head;
    int index = 0;
    while(str[index]){
        int idx = str[index] - '0';
        cur = cur->num[idx];

        
        if (cur == NULL) return 0;
        if (cur -> end == 1) return 1;
        
        index++;
    }

    return 1;
}

int main(){
    int N, T, flag = 0;
    char tmp_num[12];

    scanf("%d", &N);
    for (int i = 0; i < N;i++){
        trie *head = new_trie();
        scanf("%d", &T);
        while(T)
        {
            scanf("%s", tmp_num);
            if(!search(head,tmp_num)){
                insert(head, tmp_num);
            }
            else{
                flag = 1;
            }
            T--;
        }
        if(flag == 1){
            printf("NO\n");
            flag = 0;
        }
        else{
            printf("YES\n");
        }
    }
}