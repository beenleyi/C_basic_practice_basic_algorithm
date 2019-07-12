#include<stdio.h>
#include<stdlib.h>
int maxw(int time,int m,int t[],int v[]);
int main(){
	int t[110],v[110],time,m,i;
	scanf("%d%d",&time,&m);
	for(i=0;i<m;i++) scanf("%d%d",&t[i],&v[i]);
	printf("%d",maxw(time,m,t,v));
	system("pause");
	return 0;
}
int maxw(int time,int m,int t[],int v[]){
	int i,j;
	int w[110][1010]={0};
	for (j=0;j<m;j++)
	for (i=1;i<=time;i++){
		if (t[j]<time-i) w[j][i]=max(w[j-1][i-t[j]]+v[j],w[j-1][i]);
		else w[j][i]=w[j-1][i];
	}
	return w[m-1][time];
}
