#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
int kmax(int *a,int l,int r,int k);
int partition(int *a,int l,int r);
int main(){
	int n,*a,i,k;
	FILE *fpRead = fopen("random.txt", "r");
	if (fpRead == NULL) return 0;
	fscanf(fpRead,"%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for (i=0;i<n;i++) fscanf(fpRead,"%d",a+i);
	scanf("%d",&k);
	printf("%d",kmax(a,0,n-1,k));
} 
// 在l位置和r位置之间找第k大 
int kmax(int *a,int l ,int r,int k){
	int p;
	if (l<r)  p=partition(a,l,r);
	if (p+1==k) return *(a+p);
	else if (p+1>k) return kmax(a,l,p-1,k);
	else return kmax(a,p+1,r,k);
}
//划分，返回pivot的位置 
int partition(int *a,int l,int r){
	int i=l,j=l+1;
	while (j<=r) {
		if ((a[j]<a[l])&&(j!=++i)) swap(a[j],a[i]);
		j++;
	}
	swap(*(a+l),*(a+i));
	return i;
}
