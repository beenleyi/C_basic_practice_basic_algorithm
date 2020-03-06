#include<stdio.h>
#include<stdlib.h>
int main() {
	int m, n, **a,i,j;
	scanf_s("%d%d", &n, &m);
	a = (int **)malloc(sizeof(int *)*n);
	for (i = 0; i < n; i++)
		a[i] = (int *)malloc(sizeof(int)*m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			scanf_s("%d", &a[i][j]);
			j == m - 1 ? printf("%d\n", -10*a[i][j]) : printf("%d ", -10*a[i][j]);
		}
	for (i = 0; i < n; i++) free(a[i]);
	free(a);
	system("pause");
	return 0;
	
}

