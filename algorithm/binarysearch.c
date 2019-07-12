#include<stdio.h>
int main(){
	const int N=100;
	int n,x,i;
	int a[N];
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&x);
	int middle,left=0,right=n-1;
	while (left<=right){
		middle=(left+right)/2;
		if (x==a[middle]) break;
		if (x>a[middle]) left=middle+1;
		if (x<a[middle]) right=middle-1;
	}
	if (x==a[middle]) printf("%d",middle);else printf("NULL");
	return 0;
} 
//
//1 3 5 6 8 9 10
//7
