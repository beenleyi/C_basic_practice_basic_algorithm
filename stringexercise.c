#include<stdio.h>
#include<string.h>
int main(){
	char str1[100];
	char str2[100];
	scanf("%s",str1);
	gets(str2);// no &
	strcat(str1,str2);
	printf("%s",str1);
	printf("%s",str2);
	strcpy(str1,str2);
	puts(str1);
	puts(str2);
	strcpy(str2,"china");
	strncpy(str1,str2,3);
	// the first 3 char there is so different strncpy
	puts(str1);
	puts(str2);
}
