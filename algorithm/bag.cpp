#include<iostream>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct bag{
	int t;
	int v;
	double aver;
};
typedef struct bag knapsack;
int maxw(int time,int m,knapsack a[]);
bool comp(const knapsack &p1,const knapsack &p2);
int main(){
	int time,m,i;
	knapsack a[110];
	scanf("%d%d",&time,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&a[i].t,&a[i].v);
		a[i].aver=a[i].v/(double)a[i].t;
	}
	sort(a+1,a+m,comp);
	printf("%d",maxw(time,m,a));
	system("pause");
	return 0;
}
int maxw(int time,int m,knapsack a[]){
	int i=1,j,total=0;
	while (time){
		if (time>a[i].t) {
			total+=a[i].v;
			time-=a[i].t;
		}
		else {
			total+=time*a[i].aver;
			time=0;
		}
	}
}
bool comp(const knapsack &p1,const knapsack &p2){
	return p1.aver-p2.aver>1e-6;
}
//10 5
//2 6
//2 3
//6 5
//5 4
//4 6
//
//5 3
//71 100
//3 1
//1 2



