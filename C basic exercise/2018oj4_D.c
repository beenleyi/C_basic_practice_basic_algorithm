#include<stdio.h>
int a[100][100];
int findroadx(int m);
int findroady(int m);
int main(){
	int m,n,r,c,i,j;
	scanf("%d%d",&m,&n);
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	r=findroadx(m);//找行 
	c=findroady(n);//找列
	if (((c==0)&&(r!=0))||((c!=0)&&(r==0))) printf("1\n");
	else printf("%d\n",r*c); 
}
int findroadx(int m){
	int flag=0,i,sum;//不是街区； 
	for (i=0;i<m;i++){
		if (a[0][i]>50){
			if (flag==0) sum++;
			flag=1;
		}
		else flag=0;
	}
	return sum; 
}
int findroady(int m){
	int sum=0;
	int flag=0,i;//不是街区； 
	for (i=0;i<m;i++){
		if (a[i][0]>50){
			if (flag==0) sum++;
			flag=1;
		}
		else flag=0;
	}
	return sum;
}
