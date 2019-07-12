#include<stdio.h>
#include<stdlib.h>
int n,*x,sum=0;
void queen(int t);
void swap(int *a,int *b);
int main(){
	scanf("%d",&n);
	int i;
	x=(int*)malloc(sizeof(int)*(n+1));
	for (i=1;i<=n;i++) x[i]=i;
	queen(1);
	printf("%d",sum);
}
void queen(int t)
{
	int i,j;
	if (t>n) {
		sum++;
		for (i=1;i<=n;i++) printf("%d",x[i]);
		printf("\n");
		for (i=1;i<=n;i++) 
		for (j=1;j<=n;j++) {
			if (x[i]!=j) printf("*");else printf("1");
			if (j==n) printf("\n");
		}
	}
	else {
		for (i=t;i<=n;i++){
			int fflag=1;
			swap(&x[i],&x[t]);
			for (j=1;j<t;j++){
				if ((j-t==x[j]-x[t])||(t-j==x[j]-x[t])) {
					fflag=0;
					break;
				}
			}
			if (fflag==1) {
				queen(t+1);
				
			}
			swap(&x[i],&x[t]);
		}
	}
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
