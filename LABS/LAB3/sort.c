#include <stdio.h>

void swap(int *i, int *j)
{
	int aux = *i;
	*i = *j;
	*j = aux;
}

void ordernar(int v[], int n, int mod)
{
	for (int i = 0; i < (n - 1); i++)
	{
		int menor = i;
		for (int j = (i + 1); j < n; j++)
		{
			if (v[menor] % mod > v[j] % mod)}{
			}
		}
	}
}

int main()
{
	int n, m;

	do
	{
		scanf("%d %d", &n, &m);

		int arr[n];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		ordernar(arr, n, m);
		for (int i = 0; i < n; i++)
		{
			printf("%d\n", arr[i]);
		}
	} while (n != 0 && m != 0);
}
