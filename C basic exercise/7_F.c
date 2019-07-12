#include<stdio.h>
int findInArray(int *array,int element,int size);
int main(){
	int n,m,i,j;
	scanf("%d", &n);
	int a[1000],b[100];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
	}
	scanf("%d", &m);
	for (i=0;i<m;i++) scanf("%d",&b[i]);
	i=0;
	while(i<m) {
		j=findInArray(a,b[i],n);
		if (j == 0) {
					if (n == 1) printf("NULL");
					else printf("%d\n", a[1]); 
				}
		else if (j == n - 1) {
					printf("%d\n", a[n - 2]); 
				}
		else if (j==-1) printf("NULL\n");
		else {
					printf("%d %d\n", a[j - 1], a[j + 1]);
				}
	i++;
	}
}
int findInArray(int *array,int element,int size){
	int j=0;
	int *p=array;
	while ((*array!=element)&&(array<p+size)) array++;
	if (*array==element) return array-p;
	else return -1;
}

