#include<iostream>
#include<stdlib.h>
using namespace std;
const int INF = 1000000000;
int n,**g,s,*dist;//n���㣬����Դ�㣻g�ڽӾ���
void dijkstra(int *dist); 
int main(){
	int i,j,a,b,c;
	scanf("%d",&n);
	scanf("%d",&s);//Դ����s 
	g=(int **)malloc(sizeof(int *)*(n+1));
	for (i=1;i<=n;i++) g[i]=(int*)malloc(sizeof(int)*(n+1));
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++) g[i][j]=INF;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF){
		g[a][b]=c;
	}
	dist=(int *)malloc(sizeof(int)*(n+1));
	dijkstra(dist);
	for (i=1;i<=n;i++) printf("%d ",dist[i]); 
}
void dijkstra(int *dist){
	int *v,i,t=1,mini,u;/*v������¼�Ƿ���ʹ���
	t������¼�Ѿ������˶���Ԫ�� ����ʼ��Ϊ1�� 
	*/ 
	v=(int*)malloc(sizeof(int)*(n+1));
	
	for (i=1;i<=n;i++) {
		v[i]=0;
		dist[i]=INF; 
	}
	dist[s]=0;v[s]=1;u=s;
	while (t<n){
		for (i=1;i<=n;i++) {
			if (v[i]!=1){//û�з��ʹ��Ļ�
				if (g[u][i]+dist[u]<dist[i]) //���ֵ�ø��µĻ� 
					dist[i]=dist[u]+g[u][i];
			} 
		}
		mini=INF;
		for (i=1;i<=n;i++){
			if ((v[i]!=1)&&(dist[i]<mini)){
				mini=dist[i];
				u=i;
			}
		}
		printf("%d\n",u);
		for (i=1;i<=n;i++) printf("%d ",dist[i]);
		printf("\n");
		v[u]=1;
		t++;
	}  

}

//5 1
//1 2 10
//1 4 30
//1 5 100
//2 3 50
//3 5 10
//4 3 20
//4 5 60
