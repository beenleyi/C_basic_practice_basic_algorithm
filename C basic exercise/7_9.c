#include<stdio.h>
#define N 5
struct student{
		char ID[25];
		int sum;
	}test[100];
void sort(struct student a[],int n);
void sortname(struct student a[],int ,int );//从l开始到r
int main(){
	
	int i,n,j;
	scanf("%d",&n);
	struct student *ptr[100];
	for (i=0;i<n;i++) ptr[i]=&test[i];
	for (j=0;j<n;j++){
	scanf("%s",test[j].ID);
	scanf("%d",&test[j].sum);
	}
	sort(test,n);
	for (j=0;j<n;j++){
	printf("Name:%s\n",ptr[j]->ID);
	printf("total:%d\n",ptr[j]->sum);
	printf("\n");
	}
	return 0;
}
	
void sort(struct student a[],int n){
	int i,j;
	struct student temp;
	for (i=1;i<n;i++)
	for (j=1;j<=n-i;j++)
	if (a[j].sum>a[j-1].sum){
		temp=a[j];
		a[j]=a[j-1];
		a[j-1]=temp;
	}
	i=1;
	while(i<n){
		//找相同的分数的 
		if (a[i].sum==a[i-1].sum){
			j=i-1;
			while (a[i+1].sum==a[i].sum) i++; 
			sortname(a,j,i); 
		}
		i++;
	}
}
void sortname(struct student a[],int l,int r){
	int i,j;
	struct student temp;
	for (i=0;i<r-l;i++){//次数是r-l次 
		for (j=l+1;j<=r-i;j++){
			if ((strcmp(a[j].ID,a[j-1].ID))<0){
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			} 
		}
	}
}




