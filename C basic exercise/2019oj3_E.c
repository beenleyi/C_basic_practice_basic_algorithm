#include<stdio.h>
#define N 100010
#define MAX 1000000010
int judgeship(int a[],int k,int n,int m);
int main(){
	int n,m,i,left,right,middle;
	int a[N];
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	left=1;right=MAX;
	while (left<right){
		middle=(left+right)/2;
		if (judgeship(a,middle,n,m)) right=middle;
		else left=middle+1;
	}
	printf("%d",right); 
} 
int judgeship(int a[],int k,int n,int m){
	int ship=0;
	int i=0,remain=0;
	while(i<n){
		if (a[i]>k) return 0;
		if (remain<a[i]){
				m--;
				remain=k-a[i];
			}
			else remain-=a[i];
		i++;
		}	
	if (m>=0) return 1;else return 0;
}
