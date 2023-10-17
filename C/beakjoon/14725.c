#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 1000
#define MAX_CHILDREN 26

typedef struct TrieNode {
    struct TrieNode *children[MAX_CHILDREN];
    char *name;
} TrieNode;

TrieNode nodePool[MAX_NODE];
int nodeCnt = 0;

TrieNode* newNode() {
    for (int i = 0; i < MAX_CHILDREN; i++) {
        nodePool[nodeCnt].children[i] = NULL;
    }
    return &nodePool[nodeCnt++];
}

void insert(TrieNode* root, char** words, int count) {
    TrieNode* curr = root;

    for (int i = 0; i < count; i++) {
        int index = words[i][0] - 'A';
        if (curr->children[index] == NULL) {
            curr->children[index] = newNode();
            curr->children[index]->name = words[i];
        }
        curr = curr->children[index];
    }
}

void printTrie(TrieNode* root, int level) {
    if (root == NULL)
        return;
    
    for (int i = 0; i < MAX_CHILDREN; ++i) { 
        if(root->children[i]) { 
            for(int j=0;j<level;++j){
                printf("--");
            }
            printf("%s\n",root->children[i]->name);
            printTrie(root->children[i], level+1);
        } 
   }  
}

int main() {

   int N;
   scanf("%d", &N);

   TrieNode* root=newNode();

   for(int n=1;n<=N;++n){
       int K;
       scanf("%d",&K);
       char **words=(char**)malloc(sizeof(char*)*K);

       for(int k=1;k<=K;++k){
           words[k-1]=(char*)malloc(sizeof(char)*16);
           scanf("%s",words[k-1]);
       }

       insert(root,words,K);

      // Free the allocated memory after insertion to trie.
      for(int k=1;k<=K;++k){
          free(words[k-1]);
      }
      free(words);
   }

   printTrie(root, 0);

}
