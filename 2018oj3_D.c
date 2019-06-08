#include<stdio.h>
#include<string.h>
char a[200][21];
void sort(int num);
int main(){
	char get[21];
	int n,i,j,flag;
	char test[21];
	scanf("%s",get);
	scanf("%d",&n);
	int num=n;
	getchar();
	while(n){
		gets(test);
		strcpy(a[n],test);
		for (i=0;i<=strlen(test)-strlen(get);i++){
			flag=1;
			if (test[i]==get[0]){
				int k=i; 
				for(j=1;j<strlen(get);j++){
					if (test[k+1]!=get[j]) {
						flag=0;
						k++;
						break;
					}
					else k++;
				}
				if (flag==1) break;
			}
			else flag=0;
		}
		if (flag==0) strcpy(a[n],"a");
		if (flag==1) puts(a[n]); 
		n--;
	}
	 sort(num);
	for (i=0;i<num;i++)
	{
		if (*a[i]!='a') puts(a[i]);
	}
	return 0;
} 
void sort(int n){
	int i,j;
	char temp[21];
	for (i=1;i<n;i++)
	for (j=2;j<=n-i+1;j++)
	if (strcmp(a[j-1],a[j])>0){
		strcpy(temp,a[j-1]);
		strcpy(a[j-1],a[j]);
		strcpy(a[j],temp);
	}
}
//Î´ÒýÈëk 
