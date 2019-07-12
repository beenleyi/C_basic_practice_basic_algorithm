#include<stdio.h>
#include<stdlib.h>
struct book{
	char name[60];
	int a[8];
};
typedef struct book BOOK;
void sort(BOOK *p,int n);
void swap(BOOK *p1,BOOK *p2);
int comp(BOOK * p3,BOOK *p4);
int main(){
	int n,i,j;
	BOOK b[100];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%s",b[i].name);
		scanf("%d %d %d %d %d %d",&b[i].a[4],&b[i].a[1],&b[i].a[2],&b[i].a[3],&b[i].a[0],&b[i].a[5]);
	}
	sort(b,n);
	for (i=0;i<n;i++){
		printf("%s",b[i].name);
		printf(" %d %d %d %d %d %d\n",b[i].a[4],b[i].a[1],b[i].a[2],b[i].a[3],b[i].a[0],b[i].a[5]);
	} 
}
void sort (BOOK *p,int n){
	int i;
	BOOK *j;
	for (i=1;i<n;i++){
		for (j=p+1;j<p+n;j++){
			if (comp(j,j-1)>0) {
				BOOK temp=*j;
				*j=*(j-1);
				*(j-1)=temp;
			}
		}
	}
	return;
}
int comp(BOOK *p1,BOOK *p2){
	int i;
	if ((p1->a[0])<(p2->a[0])) return 1;
	else if ((p1->a[0])>(p2->a[0])) return 0;
	else {
		for (i=1;i<=5;i++){
			if ((p1->a[i])>(p2->a[i])) return 1;
			else if ((p1->a[i])<(p2->a[i])) return 0;
		}
	}
}
