#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int GreedySeletor(int n,int *a,int *b,int *c);
void quicksort(int *a,int *b,int p,int r);
int partition(int *a,int *b,int p,int r);
int main(){
	int n;
	scanf("%d",&n);
	int *a,*b,*c,i;
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	c=(int *)malloc(sizeof(int)*n);
	for (i=0;i<n;i++) scanf("%d%d",a+i,b+i);
	printf("%d\n",GreedySeletor(n,a,b,c));
	for (i=0;i<n;i++) if (*(c+i)!=0) printf("%d %d\n",*(a+i),*(b+i));
}
int GreedySeletor(int n,int *a,int *b,int *c){
	quicksort(a,b,0,n-1);
	int i,j,sum;
	for (i=1;i<n;i++) c[i]=0;
	c[0]=1;
	j=0;
	sum=1;
	for (i=1;i<n;i++){
		if (a[i]>b[j]) {
			c[i]=1;
			j=i;
			sum++;
		}
	}
	return sum;
}
void quicksort(int *a,int *b,int p,int r){
	int q;
	if (p<r) {
		q=partition (a,b,p,r);
		quicksort(a,b,p,q-1);
		quicksort(a,b,q+1,r);
	}
	
}
int partition(int *a,int *b,int p,int r){
	int i=p,j=p+1;
	for (;j<=r;j++){
		if ((b[j]<b[p])&&(j!=++i)){
			swap(b[j],b[i]);
			swap(a[j],a[i]);
		}
	}
	swap(b[p],b[i]);
	swap(a[p],a[i]);
	return i;
}
//11
//1 4
//3 5
//0 6
//5 7
//3 8
//5 9
//6 10
//8 11
//8 12
//2 13
//12 14













