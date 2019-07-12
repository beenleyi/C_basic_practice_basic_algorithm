#include<stdio.h>
#include<string.h>
int main() {
	int n,i,j;
	scanf("%d", &n);
	char temp[101];
	char str[200][101];
	getchar(); 
	for (i = 0; i < n; i++)
	 gets(str[i]);
	for (i = 1; i < n; i++) {
		for (j=1;j<=n-i;j++)
			if (strcmp(str[j], str[j - 1]) < 0) {
				strcpy(temp,str[j]);
				strcpy(str[j], str[j - 1]);
				strcpy(str[j - 1], temp);
		}
	}
	for (i = 0; i < n; i++) puts(str[i]);
	system("pause");
	return 0;
}




