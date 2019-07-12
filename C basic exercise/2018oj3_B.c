#include<stdio.h>
void sort(int class[],int n);//从大到小 
int main(){
	int n,i,sum;
	int class[100];
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d",&class[i]);
	}
	sort(class,n);
	for (i=0;i<n/2;i++){
		sum+=class[i]/2;
	} 
	printf("%d",sum);
}
void sort(int class[],int n){
	int i,max,j,temp;
	for (i=0;i<n-1;i++){
		max=i;
		for (j=i+1;j<n;j++){
			if (class[j]>class[max]) max=j;
		}
		temp=class[i];
		class[i]=class[max];
		class[max]=temp;
	}
	for (i=0;i<n;i++) printf("%d ",class[i]);
}
 
