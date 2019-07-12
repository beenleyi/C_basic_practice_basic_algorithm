#include<stdio.h>
#include<stdlib.h>
int **a,n,f1=0,f2=0,fm=0,ftotal=0,*x;
void swap(int *a,int *b);
void backtrack(int i); 
int main(){
	int i;
	scanf("%d",&n);
	a=(int**) malloc(sizeof(int *)*(n+1));
	x=(int *)malloc(sizeof(int)*(n+1));
	for (i=1;i<=n;i++) x[i]=i;
	for (i=1;i<=n;i++) a[i]=(int*)malloc(sizeof(int)*3);
	for (i=1;i<=n;i++) scanf("%d%d",&a[i][1],&a[i][2]);
	backtrack(1);
	printf("%d",fm);
	system("pause");
	return 0;
} 
void backtrack(int t){
	int j,i;
	if (t>n) {
		for (i=1;i<=n;i++) printf("%d ",x[i]);
		printf("\n%d\n",ftotal);
		if (fm==0) fm=ftotal;else if (fm>ftotal) fm=ftotal;
		return;
	}
	else {
		for (j=t;j<=n;j++){
			f1+=a[x[j]][1];
			int pref2=f2;
			if (f1>f2) f2=f1+a[x[j]][2];
			else f2+=a[x[j]][2];
			ftotal+=f2;
			swap(&x[t],&x[j]);
			backtrack(t+1);
			swap(&x[t],&x[j]);
			f1-=a[x[j]][1];
			ftotal-=f2;
			f2=pref2;
		}
	}
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
//4
//2 1
//6 7
//2 3
//8 9

