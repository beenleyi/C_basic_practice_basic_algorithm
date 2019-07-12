#include<stdio.h>
#define SIZE 50 
int main(){
	int floor[SIZE][SIZE]={0};
	int commands[100];
	int pen,i=0,n=0,j;
	scanf("%d",&commands[0]);
	while(commands[n]!=9){
		scanf("%d",&commands[n+1]);
		n++;
	}
	int r=24,c=24,orient=0;//orient为方向，0为向上，1为向右，2为向下，3 
	while(i<n){
		if ((commands[i]==1)||(commands[i]==2)) pen=commands[i];
		if (commands[i]==5){
			for (j=0;j<commands[i+1];j++){
				switch(orient){
					case 0:r--;break;
					case 1:c++;break;
					case 2:r++;break;
					case 3:c--;break;
				}
				if (pen==2) floor[r][c]=1;
			}
			i++; 
		}
		if (commands[i]==3) orient=(orient+1)%4;
		if (commands[i]==4) orient=(orient-1)%4;
		if (commands[i]==6) {
			for (i=0;i<SIZE;i++)
			for (j=0;j<SIZE;j++){
			if (floor[i][j]==1) printf("*");
			else printf(" ");
			if (j==SIZE-1) printf("\n"); 
		}
		}
		i++;
	}
	return 0;
}
	
