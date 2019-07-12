#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char **p,char **s,int n);
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	getchar();
	char **s,c[1010],**p;//s存输入的字符串；p存对应字符串的缩写 
	s=(char**)malloc(sizeof(char*)*(n+1));
	p=(char**)malloc(sizeof(char*)*(n+1));
	for (i=0;i<n;i++){
		gets(c);
		s[i]=(char*)malloc(sizeof(char)*(strlen(c)+5));
		strcpy(s[i],c); 
	}
	//找字符串的缩写，存到p里面 

	for (i=0;i<n;i++){
		k=0;
		char c[1010]={' '};
		for (j=0;j<strlen(s[i]);j++){
			if (s[i][j]<91) {
			c[k]=s[i][j];
			k++; 
			}
		}
		p[i]=(char*)malloc(sizeof(char)*strlen(c));
		p[i][k]='\0';
		strcpy(p[i],c);
	}
	//排序 
	sort(p,s,n);
	for (i=0;i<n;i++) puts(s[i]);
	for (i=0;i<n;i++) free(s[i]);
	free(s);
}
void sort(char **p,char **s,int n){
	char *temp;
	int i,j;
	for (i=1;i<n;i++){
		for (j=1;j<=n-i;j++){
			if (strcmp(p[j],p[j-1])<0){
				temp=s[j];
				s[j]=s[j-1];
				s[j-1]=temp;
				temp=p[j];
				p[j]=p[j-1];
				p[j-1]=temp;
			}
		}
	}
}

