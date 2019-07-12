#include<iostream>
#include<stdlib.h>
using namespace std;
const int INF = 1000000000;
int n,**g,**v,*w;
void kruskal();
int main(){
	int i,j,a,b,c;
	scanf("%d",&n);
	g=(int **)malloc(sizeof(int *)*(n+1));
	v=(int **)malloc(sizeof(int *)*(n+1));
	w=(int *)malloc(sizeof(int)*(n+1));
	for (i=1;i<=n;i++) g[i]=(int*)malloc(sizeof(int)*(n+1));
	for (i=1;i<=n;i++) v[i]=(int*)malloc(sizeof(int)*(n+1));
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++) {
		v[i][j]=0;//边置0表示生成树中没有这些边 
		g[i][j]=INF;
	}
	while (scanf("%d%d%d",&a,&b,&c)!=EOF){
		g[a][b]=c;
		g[b][a]=c;
	}
	kruskal;
}
void kruskal(){
	sort(g);
	w[1]=1;//第1个算已经加入 
	int t=1;/*t表示已经加入了多少个点，起始为1，默认从1开始 
	*/ 
	while (t<n){
		for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		t++;
	}
}
void sort(int **g){
	
}
