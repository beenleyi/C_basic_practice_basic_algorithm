#include<stdio.h>
//a存储矩阵的行列数，a[0]为第一个矩阵的行数，a[i]为第i个矩阵的列数
//s存储从i到j计算的分界点,取右点 
//m存储从i到j计算的结果 
void matrixChain(int m[][100],int s[][100],int a[100],int n);
int main(){
	int n,i;
	int m[100][100];int s[100][100];int a[100];
	scanf("%d",&n);
	for (i=0;i<=n;i++) scanf("%d",&a[i]);
	matrixChain(m,s,a,n);
	printf("%d",m[1][n]);
	//输出划分方案 
} 
void matrixChain(int m[][100],int s[][100],int a[100],int n){
	int i,j,k,temp,r;
	for (i=1;i<n;i++) m[i][i]=0;
	for (r=2;r<=n;r++){//r代表现在算的是几个矩阵的 
		for (i=1;i<=n-r+1;i++){
			j=i+r-1;
			m[i][j]=m[i][i]+m[i+1][j]+a[i-1]*a[i]*a[j];
			s[i][j]=i;
			for (k=i+1;k<j;k++){
			temp =m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
			if (temp<m[i][j]){
				m[i][j]=temp;
				s[i][j]=k;
			} 
		}
	}
} 
}
// 30 35 15 5 10 20 25 
