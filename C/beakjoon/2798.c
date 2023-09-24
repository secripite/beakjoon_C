#include<stdio.h>
#include <stdlib.h>

int main() {
	int num, target,temp=0,i=0;
	int arr[100];
	scanf("%d %d", &num, &target);

	do {
		scanf("%d", &arr[i]);
		i++;
	}while (getc(stdin) == ' ');

	for (i = 0; i < num; i++)
		for (int j = i + 1; j < num; j++)
			for (int n = j + 1; n < num; n++)
			{
				if (arr[i] + arr[j] + arr[n] > target)
					continue;
				if (target - (arr[i] + arr[j] + arr[n]) < target - temp)
					temp = arr[i] + arr[j] + arr[n];
			}
	printf("%d", temp);
}