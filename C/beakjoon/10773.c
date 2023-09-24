#include<stdio.h>

int main() {
	int stacker[100000];
	int top=0,num;
	int temp,result=0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		if (temp != 0)
		{
			stacker[top] = temp;
			top++;
		}
		else
		{
			top--;
		}
	}

	for (int j = top-1; j >= 0; j--)
	{
		result += stacker[j];
	}

	printf("%d", result);
}