#include<stdio.h>
#include<string.h>
int main() {
	char str[10010];
	int newword = 1,i=0,j=0,k;
	char *word[1010];
	gets(str);
//�����ʱ��Ͳ�����ǰ���ո�
//wordָ�������¼����λ��
//����ֱ�ӽ�str�еĿո���Ϊ\0������str��ֻ�е�һ�����ʣ���Ϊ����Ķ�ʧ
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
	//ע���β�����Ѿ�û�пո��ˣ����һ�����ʾ���\0��β�����Բ���ֻ�ҿո񣬷�������Խ��
		while ((*(word[i] + k) != ' ')&&(*(word[i]+k)!='\0')) k++;
		*(word[i] + k) = '\0';
	}
	//	printf("%d", j);
	//����Ӧ�����word[i]ָ��
	for (i = 0; i < j; i++) puts(word[i]);
	system("pause");
	return 0;
	
}
