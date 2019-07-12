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
		//s[i]=c;是错的，这样会使s[i]直接指向c的地址，c的地址在定义的时候已经确定。而在继续读入c的时候，会将前面已经赋值过的全部又变成新的c串 
		strcpy(s[i],c);
	}
	sort(s,n);
	for (i=0;i<n;i++) puts(s[i]);
	for (i=0;i<n;i++) free(s[i]);//愚蠢至极，居然忘记写循环了 
	free(s);
} 
void sort(char **s,int n){
	int i,j;
	char *temp;
	for (i=1;i<n;i++)//只排n-1次 
	for (j=1;j<=n-i;j++){
		if (strcmp(s[j],s[j-1])<0){
			temp=s[j];
			s[j]=s[j-1];
			s[j-1]=temp;
		}
	}
}
