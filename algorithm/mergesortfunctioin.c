#include<stdio.h>
void mergeSort(int a[],int n);//ֻҪ֪��a��a�ĳ��ȾͿ������� 
void mergepass(int a[],int b[],int s,int n); //s��ʾ������n���ɱ�ʾ����ĳ���
//b�Ǹ������� 
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
	//������������һ�����⣺s�����ѭ���мӵ�һ�γ�����n��ô�죬��ϵ������mergepass�����ô����ɡ� 
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
