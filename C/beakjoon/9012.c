#include<stdio.h>

int main() {
	int num;
	int j;
	int counter;
	char str[256];

	scanf_s("%d\n", &num);

	for (int i = 0; i < num; i++)
	{
		gets_s(str);
		j = 0;
		counter = 0;
		while (str[j] != NULL)
		{
			if (counter < 0)
				break;

			if (str[j] == '(')
			{
				counter++;
			}
			else if (str[j] == ')')
			{
				counter--;
			}
			j++;
		}
		if (counter == 0)
			printf("YES\n");
		else
			printf("NO");
	}
}