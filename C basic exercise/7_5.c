#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char **s,int n);
int main(){
	int n,i;
	char c[1010],**s;
	scanf("%d",&n);
	getchar();
	s=(char **)malloc(sizeof(char*)*n);
	for (i=0;i<n;i++){
		gets(c);
		s[i]=(char *)malloc(sizeof(char)*(strlen(c)+5));
		//s[i]=c;�Ǵ�ģ�������ʹs[i]ֱ��ָ��c�ĵ�ַ��c�ĵ�ַ�ڶ����ʱ���Ѿ�ȷ�������ڼ�������c��ʱ�򣬻Ὣǰ���Ѿ���ֵ����ȫ���ֱ���µ�c�� 
		strcpy(s[i],c);
	}
	sort(s,n);
	for (i=0;i<n;i++) puts(s[i]);
	for (i=0;i<n;i++) free(s[i]);//�޴���������Ȼ����дѭ���� 
	free(s);
} 
void sort(char **s,int n){
	int i,j;
	char *temp;
	for (i=1;i<n;i++)//ֻ��n-1�� 
	for (j=1;j<=n-i;j++){
		if (strcmp(s[j],s[j-1])<0){
			temp=s[j];
			s[j]=s[j-1];
			s[j-1]=temp;
		}
	}
}
