#include<stdio.h>
#include<string.h>
void delcharfun(char *str, char ch);
int main() {
	char s[101];
	char c ;
	scanf("%s", s);
	getchar();
	scanf("%c", &c);
	delcharfun(s, c);
	return 0;
}
void delcharfun(char *str, char ch) {
	int i = 0;
	while (*str!='\0') {
		if (*str != ch) printf("%c", *str);
		str++;
	}
	printf("\n");
}
