#include<stdio.h>
#include<string.h>
int main() {
	char str[10010];
	int newword = 1,i=0,j=0,k;
	char *word[1010];
	gets(str);
//读入的时候就不读入前导空格
//word指针数组记录单词位置
//不能直接将str中的空格置为\0，否则str就只有第一个单词，因为后面的丢失
	for (; i < strlen(str); i++) {
		if (str[i] == ' ') newword = 1;
		else if (newword == 1) {
			word[j] = &str[i];
			newword = 0;
			j++;
		}
	}
	for (i = 0; i < j; i++) {
		k = 1;
	//注意结尾可能已经没有空格了，最后一个单词就是\0结尾，所以不能只找空格，否则数组越界
		while ((*(word[i] + k) != ' ')&&(*(word[i]+k)!='\0')) k++;
		*(word[i] + k) = '\0';
	}
	//	printf("%d", j);
	//就是应该输出word[i]指针
	for (i = 0; i < j; i++) puts(word[i]);
	system("pause");
	return 0;
	
}
