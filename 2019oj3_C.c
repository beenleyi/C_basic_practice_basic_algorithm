#include<stdio.h>
int main(){
	int n,i,j,sum;
	scanf("%d",&n);
	char a[20];//diyiwzzl0
	int b[18]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char ch[11]="10X98765432";
	getchar();
	while(n){
		sum=0;
		gets(a);
		for (i=0;i<17;i++) sum=sum+(a[i]-48)*b[i];
		if (ch[sum%11]==a[17]) printf("right\n");
		else printf("wrong\n");
		n--;
	}
}
