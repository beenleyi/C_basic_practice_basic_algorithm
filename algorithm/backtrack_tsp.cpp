#include<iostream>
using namespace std;
#include<stdio.h>
int n,line[110][110]={0},bestw=0,w=0,bestx[110],x[110];
void backtrack(int i);
int main(){
	int a,b,c,i;
	scanf("%d",&n);
	bestw=100000;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF){
		line[a][b]=c;
		line[b][a]=c;
	}
	for (i=1;i<=n;i++) x[i]=i;
	backtrack(2);
	printf("%d\n",bestw);
}
void backtrack(int t){
	int i;
	if (t==n) {
		if ((line[x[t-1]][x[t]]!=0)&&(line[x[t]][x[1]]!=0)){
			w+=line[x[t-1]][x[t]]+line[x[t]][x[1]];
		if (w<bestw) {
			bestw=w;
			for (i=1;i<=n;i++) bestx[i]=x[i];
		}
		for (i=1;i<=n;i++) {
			printf("%d ",x[i]);
		}
		printf("\n%d\n",w);
		w-=line[x[t-1]][x[t]]+line[x[t]][x[1]];
		}
	}
	else for (i=t;i<=n;i++){
		if (line[x[t-1]][x[i]]!=0){
			w+=line[x[t-1]][x[i]];
			if (w<bestw){
				swap(x[i],x[t]);
				backtrack(t+1);
				w-=line[x[t-1]][x[t]];
				swap(x[i],x[t]);
			} 
		}
	}
}

//4
//1 2 30
//1 3 6
//1 4 4
//2 3 5
//2 4 10
//3 4 20


