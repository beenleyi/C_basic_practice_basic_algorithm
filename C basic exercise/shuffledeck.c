#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define COL 4
#define NUM 13
void shuffle (int deck[][COL]);
void printdeck(int deck[][COL]);
int main(){
	srand(time(NULL));
	int deck[NUM][COL]={0};
	shuffle(deck);
	printdeck(deck);
	return 0;
}
void shuffle(int deck[][COL]){
	int n=1;//记录已经发了几张 
	int i,j;
	i=rand()%13;
	j=rand()%4;
	while (n<=COL*NUM){
		while(deck[i][j]!=0){
			i=rand()%13;
			j=rand()%4;	
		}
		deck[i][j]=n;
		n++;
	}
}
void printdeck(int deck[][COL]){
	int l;
	int i=0,j=0;
	for (l=1;l<=COL*NUM;l++){
			for (i=0;i<NUM-1;i++){
			for (j=0;j<COL-1;j++){
				if (deck[i][j]==l) break;
			}
			if (deck[i][j]==l) break;
		}
		printf("%d %d %d\n",i,j,l);
	}
}
