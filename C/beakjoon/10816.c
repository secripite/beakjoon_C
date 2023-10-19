#include <stdio.h>
#include <stdlib.h>

typedef struct node_{
    int key;
    int value;
    int end;
    struct node_ *next;
} node;

node *new_node(){
    node *Node = (node *)malloc(sizeof(node));

    Node->key = 0;
    Node->end = 0;
    Node->value = 0;
    Node->next = NULL;
    return Node;
}

void Insert(node *head, int num);
int search(node *head, int num);

int main(){
    int N,num1,M,num2;

    node *head = new_node();
    head->end = 1;
    scanf("%d", &N);
    for (int i = 0; i < N;i++){
        scanf("%d", &num1);
        Insert(head, num1);
    }

    scanf("%d", &M);
    for (int i = 0; i < M;i++){
        scanf("%d", &num2);
        printf("%d ", search(head, num2));
    }
}


void Insert(node *head,int num){
    node *cur = head;

    while(1){
        if(cur->key != num && cur->end == 1)
        {
            cur->end = 0;
            cur->next = new_node();
            cur->next->key = num;
            cur->next->end = 1;
            cur->next->value += 1;
            return;
        }
        else if(cur->key == num){
            cur->value += 1;
            return;
        }
        cur = cur->next;
        }
}

int search(node *head, int num){
    node *cur = head;

    while (1)
    {
        if(cur->key == num){
            return cur->value;
        }
        if(cur->end == 1){
            return 0;
        }
        cur = cur->next;

    }
}