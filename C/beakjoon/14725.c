#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NameMax 16
#define childMAX 26

typedef struct trie_
{
    struct trie_ *children[childMAX];
    char name[NameMax];
    int end;
}trie;

trie *new_node(){
    trie *node = (trie*)malloc(sizeof(trie));
    for (int i = 0; i < childMAX;i++){
        node->children[i] = NULL;
    }
    node -> end =0;
    return node;
}
void Insert(trie *head, char **word, int level);
void printTrie(trie *head, int level);

int main(){
    int N, K;
    scanf("%d", &N);

    trie *head = new_node();

    for (int i = 0; i < N;i++){
        scanf("%d", &K);
        char **words = (char **)malloc(sizeof(char *) * K);
        for (int i = 0; i < K;i++){
            words[i] = (char *)malloc(sizeof(char) * 16);
            scanf("%s", words[i]);
        }

        Insert(head, words, K);

        for(int k=1;k<=K;++k){
          free(words[k-1]);
        }
        free(words);
    }

       printTrie(head, 0);
}

void Insert(trie *head,char **word,int level){
    trie *cur = head;

    for (int i = 0; i < level;i++){
        int index = word[i][0] - 'A';
        if (cur->children[index]==NULL  || strcmp(cur->children[index]->name,word[i])){
            cur->children[index] = new_node();
            strcpy(cur->children[index]->name, word[i]);
        }
        cur = cur->children[index];
    }
}

void printTrie(trie *head,int level){
    if(head == NULL) return;

    for (int i = 0; i < childMAX; ++i){
        if(head->children[i]){
            for (int i = 0; i < level;i++){
                printf("--");
            }
            printf("%s\n", head->children[i]->name);
            printTrie(head->children[i], level + 1);
        }
    }
}