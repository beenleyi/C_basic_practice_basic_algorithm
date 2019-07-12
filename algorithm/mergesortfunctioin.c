#include<stdio.h>
void mergeSort(int a[],int n);//只要知道a和a的长度就可以排序 
void mergepass(int a[],int b[],int s,int n); //s表示步长，n依旧表示数组的长度
//b是辅助数组 
void merge(int a[],int b[],int l,int m,int r ) ;
int main() {
	FILE *fpRead = fopen("random.txt", "r");
	if (fpRead == NULL) return 0;
	int n, i;
	int a[101000];
	fscanf(fpRead,"%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fpRead, "%d", &a[i]);
	}
	//	insertSort(a,n);
	mergeSort(a, n);
	system("pause");
	return 0;
} 
void mergeSort(int a[],int n){
	int s=1;int b[100010];int i;
	while (s<n){
		mergepass(a,b,s,n);
		s+=s;
		mergepass(b,a,s,n);
		s+=s; 
	}
	for (i=0;i<n;i++) printf("%d ",a[i]);
	//这里容易引起一个问题：s如果在循环中加的一次超过了n怎么办，关系不大，在mergepass中做好处理即可。 
}
void mergepass(int a[],int b[],int s,int n){
	int l=0,i;
	while (l<=n-2*s){
		merge(a,b,l,l+s,l+2*s);
		l=l+2*s;
	}
	if (l+s<n) merge(a,b,l,l+s,n);
	else for (i=l;i<n;i++) b[i]=a[i];
} 
void merge(int a[],int b[],int l,int m,int r){
	int i=l,j=m,k=l;
	while ((i<m)&&(j<r)){
		if (a[i]<a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	if (i<m) while (i<m) b[k++]=a[i++];
	else while (j<r) b[k++]=a[j++];
}
