#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char *p[110],int n);
int main() {
	int n,i,j=0;
	char a[100100];
	char *p[110];
	scanf_s("%d", &n);
	//要将数字后面的空格吃掉 
	getchar();
	//j用来记录已经写到字符数组a的哪一位了。
	//对于数组来说，只要没有被认为是一个字符串，那么中间是可以有\0的
	//为了让p只指向对应的一个句子，必须不能吃掉每个字符串后面的\0 
	for (i = 0; i < n; i++) {
		gets(&a[j]);//取址a[j]不然是一个字符 
		p[i] = &a[j];
		j = j+strlen(&a[j])+1;
		}
	sort(p,n);
	
	for (i = 0; i < n; i++) puts(p[i]);
	system("pause");
	return 0;
	
}
void sort(char *p[110],int n) {
	int i, j;
	char *temp;
	//使用指向字符的指针而非字符指针数组，因为只需要交换一个地址
	//一开始的思路是使用字符数组，交换字符串，但是由于字符串的大小不同
	//而地址固定，则容易导致字符串不再完整 
	for (i = 1; i < n; i++) {
		for (j =1; j <= n -i; j++) {
			if (strcmp(p[j], p[j - 1])<0) {
			temp=p[j];
			p[j]=p[j-1];
			p[j-1]=temp;
			}
		}
	}
}
