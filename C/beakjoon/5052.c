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

void insert(char str[], trie* head){
    trie *cur = head;
    int index = 0;
    while(str[index])
    {
        int idx = num[index] - '0';
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
        idx = str[index] - '0';
        cur = cur->num[idx];

        if (cur == NULL) return 0;
        
        index++;
    }

    return cur->end;
}

int main(){
    int N, T, flag = 0;
    char tmp_num[11];

    trie*head = new_trie();

    scanf("%d", &N);
    for (int i = 0; i < N;i++){
        
        while(1)
        {
            scanf("%s", tmp_num);
            if(!search(head,tmp_num)){
                insert(head, tmp_num);
            }
            else{
                flag = 1;
            }
        }
    }
}