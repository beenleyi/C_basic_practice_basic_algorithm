#include<stdio.h>
int binarySearch(int a[],int x,int left,int right);
int main(){
	int n=10;
	int a[10];
	int i,x;
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	while(n){
		scanf("%d",&x);
		printf("%d",binarySearch(a,x,0,n-1));
		n--;
	}
	return 0;
}
int binarySearch(int a[],int x,int left,int right){
	int middle;
	middle=(left+right)/2;
	while ((left<=right)&&(a[middle]!=x)){
		middle=(left+right)/2;
		if (x>a[middle])  left=middle+1;
		else right=middle-1;
	}
	if (a[middle]==x) return middle;
	else return -1;

}
