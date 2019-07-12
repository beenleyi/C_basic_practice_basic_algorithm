#include<stdio.h>
int main(){
	int x,n;
	scanf("%d%d",&x,&n);
	printf("%d",mypower(x,n));
	return 0;
}

int mypower(int a,int n){
	if (n==0) return 1;
	if (n%2==0) return mypower(a*a,n/2);
	else return mypower(a*a,(n-1)/2)*a;
}

