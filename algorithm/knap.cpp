#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
int maxw(int time,int m,int t[],int v[]);
int main(){
	int t[110],v[110],time,m,i;
	scanf("%d%d",&time,&m);
	for(i=1;i<=m;i++) scanf("%d%d",&t[i],&v[i]);
	printf("%d",maxw(time,m,t,v));
	system("pause");
	return 0;
}
int maxw(int time,int m,int t[],int v[]){
	int i,j;
	int w[1010]={0};
	for (j=1;j<=m;j++)
	for (i=time;i>=1;i--){
		if (t[j]<=i) w[i]=max(w[i-t[j]]+v[j],w[i]);
	}
	return w[time];
}

