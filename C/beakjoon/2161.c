#include<stdio.h>
#define MAX 1000

int queue[MAX + 1];
int head = 0;
int tail = 0;
int size = 0;

void enque(int num) {
	tail = (tail + 1) % MAX;
	queue[tail] = num;
	size++;
}

int deque() {
	head = (head + 1) % MAX;
	size--;
	return queue[head];
}

int main() {
    int N;

    scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		enque(i);
	}

	while (size != 0)
	{
		for (int i = 0; i <= 1; i++) {
            if(i == 0){
                printf("%d ", deque());
            }
            else{
                enque(deque());
            }
		}
	}
	return 0;
}