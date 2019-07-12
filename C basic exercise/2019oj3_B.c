#include<stdio.h>
#define ROWS 9
#define COLS 9 
int main(){
	char a[ROWS+2][COLS+2];
	int i,n,r,c,j,sum;
//避免写得太复杂用脑过度，直接先赋值所有的地方为N，然后再读入，由于字符串的读入最后是'\0' ,所以最后再赋值为N
for(i=0;i<ROWS+2;i++) for(j=0;j<ROWS+2;j++)	 a[i][j] = 'N' ;

//	for (i=0;i<ROWS+2;i++) puts(a[i]);这简直是世界上最搞笑的事情——一直都不知道为什么输出a[i]，其N的个数都超出了列数，原因是把后面几列都输出了！a[i]是一个地址！ 
	for (i=1;i<=ROWS;i++) {
		gets(&a[i][1]);
		a[i][COLS+1]='N';
	}
//使用二维数组存储坐标 
	int pos[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
//	for (i=0;i<ROWS+2;i++) puts(a[i]);
//	for (i=1;i<=ROWS;i++) gets(&a[i][1]);
	 
//	for (i=0;i<=COLS+1;i++) {
//		a[0][i]='N';
//		a[i][0]='N';
//		a[ROWS+1][i]='N';
//		a[i][COLS+1]='N';
//	}
	scanf("%d",&n);
	while(n--){//为什么n--有n次 
		scanf("%d%d",&r,&c);
		sum=0;
	for (i=0;i<8;i++) sum+='N'-a[r+pos[i][0]][c+pos[i][1]];
		printf("%d\n",sum);
	}
	return 0;
} 
