#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char *p[110],int n);
int main() {
	int n,i,j=0;
	char a[100100];
	char *p[110];
	scanf_s("%d", &n);
	//Ҫ�����ֺ���Ŀո�Ե� 
	getchar();
	//j������¼�Ѿ�д���ַ�����a����һλ�ˡ�
	//����������˵��ֻҪû�б���Ϊ��һ���ַ�������ô�м��ǿ�����\0��
	//Ϊ����pָֻ���Ӧ��һ�����ӣ����벻�ܳԵ�ÿ���ַ��������\0 
	for (i = 0; i < n; i++) {
		gets(&a[j]);//ȡַa[j]��Ȼ��һ���ַ� 
		p[i] = &a[j];
		j = j+strlen(&a[j])+1;
		}
	sort(p,n);
	
	for (i = 0; i < n; i++) puts(p[i]);
	system("pause");
	return 0;
	
}
void sort(char *p[110],int n) {
	int i, j;
	char *temp;
	//ʹ��ָ���ַ���ָ������ַ�ָ�����飬��Ϊֻ��Ҫ����һ����ַ
	//һ��ʼ��˼·��ʹ���ַ����飬�����ַ��������������ַ����Ĵ�С��ͬ
	//����ַ�̶��������׵����ַ����������� 
	for (i = 1; i < n; i++) {
		for (j =1; j <= n -i; j++) {
			if (strcmp(p[j], p[j - 1])<0) {
			temp=p[j];
			p[j]=p[j-1];
			p[j-1]=temp;
			}
		}
	}
}
