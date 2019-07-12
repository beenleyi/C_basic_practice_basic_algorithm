#include<stdio.h>
#include<math.h>
#include<string.h>
void sort(char a[],int n);

int main(){
	int t,i,j;
	char a[105],b[105];
	const int alpha=24;
	gets(a);
	gets(b);
	int flag=0;
	if (strlen(a)!=strlen(b)) printf("NO");
	sort(a,strlen(a));
	for (i=1;i<alpha;i++){
		for (j=0;j<strlen(b);j++){
		b[j]=(b[j]-65+1)%alpha+65;
		}
		sort(b,strlen(b));
		if (strcmp(a,b)==0) {
			flag=1;
			break;
		}
	}
	if (flag==1) printf("YES") ;else printf("NO");
	return 0;
}
void sort(char a[],int n){
	int i,j;
	for (i=1;i<n;i++)
	for (j=1;j<n;j++){
		if (a[j-1]<a[j]){
			char c=a[j];
			a[j]=a[j-1];
			a[j-1]=c;
		}
	}
}
