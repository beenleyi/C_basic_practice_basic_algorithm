#include<stdio.h>
#define ROWS 9
#define COLS 9 
int main(){
	char a[ROWS+2][COLS+2];
	int i,n,r,c,j,sum;
//����д��̫�������Թ��ȣ�ֱ���ȸ�ֵ���еĵط�ΪN��Ȼ���ٶ��룬�����ַ����Ķ��������'\0' ,��������ٸ�ֵΪN
for(i=0;i<ROWS+2;i++) for(j=0;j<ROWS+2;j++)	 a[i][j] = 'N' ;

//	for (i=0;i<ROWS+2;i++) puts(a[i]);���ֱ�����������Ц�����顪��һֱ����֪��Ϊʲô���a[i]����N�ĸ�����������������ԭ���ǰѺ��漸�ж�����ˣ�a[i]��һ����ַ�� 
	for (i=1;i<=ROWS;i++) {
		gets(&a[i][1]);
		a[i][COLS+1]='N';
	}
//ʹ�ö�ά����洢���� 
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
	while(n--){//Ϊʲôn--��n�� 
		scanf("%d%d",&r,&c);
		sum=0;
	for (i=0;i<8;i++) sum+='N'-a[r+pos[i][0]][c+pos[i][1]];
		printf("%d\n",sum);
	}
	return 0;
} 
