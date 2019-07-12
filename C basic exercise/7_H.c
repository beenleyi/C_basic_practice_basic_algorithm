#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int *a,int n,int key);
int main(){
	int n,m,i;
	int *a,*b;
	scanf("%d",&n);
	scanf("%d",&m);
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*m);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	for (i=0;i<m;i++) {
		scanf("%d",&b[i]);
		i!=m-1?printf("%d ",BinarySearch(a,n,b[i])):printf("%d\n",BinarySearch(a,n,b[i]));
	}
	return 0;
}
int BinarySearch(int *a,int n,int key){
	int *left=a,*right=a+n-1,*middle;
	while (left<right){
		middle=a+(left-a+right-a)/2;
		if (*middle==key) return middle-a;
		else if (*middle<key) left=middle+1;
		else right=middle;
	}
	if (key==*left) return left-a;
	else return -1;
}

