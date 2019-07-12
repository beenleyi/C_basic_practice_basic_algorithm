#include<stdio.h>
#include<string.h>
int main(){
	int n,i;
	scanf("%d",&n);
	char a[100000];
	int ptr[100];
	int k=0;
	for (i=0;i<n;i++) {
		gets(a[k]);
		k+=strlen(a[k])+1;
		ptr[i]=a[k];
	}
	for (i=0;i<n;i++) puts(ptr[i]); 
}
