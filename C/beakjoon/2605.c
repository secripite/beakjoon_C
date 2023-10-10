#include<stdio.h>

int stack[101];
int queue[101];
int top = 0;
int head = 0;
int tail = 0;
int size = 0;

void push(int num)
{
    stack[top] = num;
    top++;
}

int pop()
{
    return (stack[top--]);
}

void enque(int num) {
	tail = (tail + 1) % 101;
	queue[tail] = num;
	size++;
}

int deque() {
	head = (head + 1) % 101;
	size--;
	return queue[head];
}

int main(){

    int cnt;
    int numbers[101]={0,};
    int temp;

    int ya, si;

    scanf("%d", &cnt);
    cnt--;

    for (int i = 0; i < cnt;i++){
        scanf("%d ", &numbers[i]);
    }

    for (int j = 0; j < cnt;j++){
        temp = numbers[j];
        printf("num : %d\n", numbers[j]);
        while (temp != 0)
        {
            ya = pop();
            printf("ya : %d\n", ya);
            enque(ya);
            temp--;
        }
        j++;
        push(j);
        j--;
        while(size != 0){
            si = deque();
            printf("si : %d\n", si);
            push(si);
        }
    }
    while (top != 0)
    {
        printf("%d ", pop());
    }
    printf("%d", pop());
}