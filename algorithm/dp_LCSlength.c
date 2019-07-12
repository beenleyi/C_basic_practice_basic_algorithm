#include<stdio.h>
void LCSlength(char a[],char b[],int m,int n,int c[][100],int state[][100]);
int main(){
	int n,m,i,j;
	char  a[100],b[100];int c[100][100],state[100][100];
	scanf("%d%d",&n,&m);
	getchar();
	gets(&a[1]);
	gets(&b[1]);
	LCSlength(a,b,n,m,c,state);
	printf("%d\n",c[n][m]);
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++) j==m?printf("%d\n",c[i][j]):printf("%d ",c[i][j]);
	return 0;
}
void LCSlength(char a[],char b[],int n,int m,int c[100][100],int state[100][100]){
	int i,j;
	for (i=1;i<=n;i++) c[i][0]=0;
	for (j=1;j<=m;j++) c[0][j]=0;
	c[0][0]=0;
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++){
		if (a[i]==b[j]) {
			state[i][j]=1;
			c[i][j]=c[i-1][j-1]+1;
		}
		else {
			if (c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				state[i][j]=2;
			}
			else {
				c[i][j]=c[i][j-1];
				state[i][j]=3;
			}	
		}
	}
}
//7 6 
//ABCBDAB
//BDCABA
 
