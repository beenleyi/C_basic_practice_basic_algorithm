#include<stdio.h>
#include<string.h>
int row(char ch,int r);
int col(char ch,int c);
int main(){
	char desk[10][10];
	int i,j,r,c;
	char pace[30];
	char ori;
	for (i=0;i<8;i++) gets(desk[i]);
	scanf("%d%d",&r,&c);
	getchar();
	gets(pace);
	ori=desk[r][c];//得到第一个位置的字符 
	for (i=0;i<strlen(pace);i++){
		r=row(pace[i],r);
		c=col(pace[i],c);
		pace[i]=desk[r][c];
	}
	printf("%c",ori);
	printf("%s",pace);
	return 0;
}
int row(char ch,int r){
	switch(ch){
		case '1':return r-1;break;
		case '2':return r-2;break;
		case '3':return r-2;break;
		case '4':return r-1;break;
		case '5':return r+1;break;
		case '6':return r+2;break;
		case '7':return r+2;break;
		case '8':return r+1;break;
	}
}
int col(char ch,int c){
	switch(ch){
		case '1':return c-2;break;
		case '2':return c-1;break;
		case '3':return c+1;break;
		case '4':return c+2;break;
		case '5':return c+2;break;
		case '6':return c+1;break;
		case '7':return c-1;break;
		case '8':return c-2;break;
	}
}
