
/*
#include<stdio.h>
#include <stdlib.h>

int main() {
	int N, K, j = 0,i,cnt=0;
	int memo[5001] = {0,};

	scanf("%d %d", &N, &K);

	printf("<");

	for (i = 0; j < N; i++,cnt++) {
		if (memo[i]) {
			cnt--;
		}
		if (i > N)
			i -= N;
		if (!(memo[i]) && cnt == K) {
			memo[i] = 1;
			cnt = 0;
			if (j == N - 1) {
				printf("%d>", i);
			}
			else
			{
				printf("%d, ", i);
			}
			j++;
		}

	}
}
*/
=====================================================

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 5000

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
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		enque(i);
	}

	int cnt = 0;
	printf("<");
	while (size != 0)
	{
		for (int i = 1; i <= K; i++) {
			if (i == K) {
				++cnt;
				if (cnt == N) {
					printf("%d", deque());
				}
				else {
					printf("%d, ", deque());
				}
			}
			else{
				enque(deque());
			}
		}
	}
	printf(">");
	return 0;
}