#include<stdio.h>
//pʼλ��rĩλ���ҵ�kλ 
int search(int a[],int p,int r,int k);
//��ʼΪp��ĩλΪr���ֿ����� 
int partition(int a[],int p,int r);
int main(){
	int n,k;
	int a[100100];
	scanf("%d",&n);
	scanf("%d",&k);
	for (i=1;i<n;i++) scanf("%d",&a[i]);
	printf("%d",search(a,0,n-1,k));
	return 0;
}
int search(int a[],int p,int r,int k){
	q=partition(a,p,r);
	if (q+1<k) search(a,q+1,r,);
	else  if (q+1>k) search(a,p,q-1,);
	else if (q+1==k) return a[q+1];
}
//�ҵ�5�� 
//49 38 65 97 76 13 27
//27 38 13 49 76 65 97 ����3 
//p r p+q q=3 k=5 p+k-1

