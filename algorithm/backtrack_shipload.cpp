#include<iostream>
using namespace std;
#include<stdio.h>
int maxx=0,r=0,bestx[110],x[110];
void maxm(int c,int m,int w[],int s,int t);
int main(){
	int i=0,c1,m,w[110],s=0;
	scanf("%d",&c1);
	scanf("%d",&m);
	for (i=1;i<=m;i++) {
		scanf("%d",&w[i]);
		r+=w[i];
	}
	maxm(c1,m,w,s,1);//ѡ�ڼ��� 
	printf("%d\n",maxx);
//	for (i=1;i<=m;i++) printf("%d",bestx[i]); 
	system("pause");
	return 0;
}
void maxm(int c,int m,int w[],int s,int t){
	int i;
	if (t>m) {
		maxx=s;
//		for (i=1;i<=m;i++) bestx[i]=x[i];
//		for (i=1;i<=m;i++) printf("%d ",x[i]);
		printf("\n");
		return;//return ���������ֹ�����ֽ�maxmִ��һ�� 
	}
	r-=w[t];
		if (c>=w[t]) {
			x[t]=1;
			s+=w[t];
			maxm(c-w[t],m,w,s,t+1);
			s-=w[t];//ע�����ѭ���ڣ����������if��������û��ȥ 
		}
		if (r+s>maxx) {
			x[t]=0;
			maxm(c,m,w,s,t+1);
		}
		r+=w[t];
}
