#include<stdio.h>
#include<stdlib.h>
int findsubmax1(int *a,int n);
int main(){
	int n,i;
	int *a;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for (i=0;i<n;i++) scanf("%d",a+i);
	printf("%d\n",findsubmax1(a,n));
}
//int findsubmax(int *a,int n){
//	int *sum,max,min,i,j;
//	sum=(int *)malloc(sizeof(int)*n);
//	for (i=0;i<n;i++) *(sum+i)=0;
//	for (i=0;i<n;i++) 
//	for (j=0;j<i+1;j++)  sum[i]+=a[j];
//	max=sum[0];min=sum[0];
//	for (i=1;i<n;i++) if (sum[i]>max) max=sum[i];
//	for (i=1;i<n;i++) if (sum[i]<min) min=sum[i];
//	if (max-min>max) return max-min ;else return max;
//}

int findsubmax1(int *a,int n){
	int b=*a,max=*a,i;
	for (i=1;i<n;i++) {
		if (b>0) b+=*(a+i);
		else b=a[i];
		if (b>max) max=b;
	}
	return max;
}

 
