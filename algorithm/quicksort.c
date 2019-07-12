#include<stdio.h>
#include<stdlib.h>
void insertSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int *a, int p, int r);
int  partition(int *a, int p, int r);
int main() {
	FILE *fpRead = fopen("random.txt", "r");
	if (fpRead == NULL) return 0;
	int n, i;
	int *a;
	fscanf(fpRead, "%d", &n);
	a = (int *)malloc(sizeof(int)*(n + 1000));
	for (i = 0; i < n; i++) {
		fscanf(fpRead, "%d", &a[i]);
	}
	//insertSort(a,n);
	//mergeSort(a, n);
	quickSort(a, 0, n - 1);
	for (i = 0; i<n; i++) printf("%d ", a[i]);
	system("pause");
	return 0;
}
//升序算法 
void insertSort(int a[], int n) {
	int i, j, k;
	int b[100];
	b[0] = a[0];
	for (i = 1; i<n; i++) {
		j = 0;
		while ((a[i]>b[j]) && (j<i)) j++;//j此指向比a【i】大的值 
		for (k = i; k>j; k--) b[k] = b[k - 1];
		b[j] = a[i];
	}
	for (i = 0; i<n; i++) printf("%d ", b[i]);
}

void mergeSort(int a[], int n) {
	int t = 1;//步长
	int  start;//指向要排序的两组的开头
	int b[101000];
	int i, j, k;
	while (t < n) {
		start = 0;
		while (start < n) {
			if (start + t >= n) break;
			i = start; j = start + t; k = 0;
			while ((i < start + t) && (j < start + 2 * t) && (j < n)) {
				if (a[i] <= a[j]) {
					b[k] = a[i];
					i++;
				}
				else {
					b[k] = a[j];
					j++;
				}
				k++;
				if (i < start + t)
					while ((i < start + t) && (i < n)) {
						b[k] = a[i];
						k++; i++;
					}
				else
					while ((j < start + 2 * t) && (j < n)) {
						b[k] = a[j];
						k++; j++;
					}
				k = 0;
				for (i = start; (i < start + 2 * t) && (i < n); i++) {
					a[i] = b[k]; k++;
				}
				//int b[N]={0};
				start += 2 * t;
			}
			t *= 2;
		}

	}
	for (i = 0; i < n; i++) printf("%d ", a[i]);
}
void quickSort(int *a, int p, int r) {
	int q;
	if (p<r) {
		q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);//注意不是q，q已经是一个分界点 
	}
}
int partition(int *a, int p, int r) {
	int x = a[p]; int temp;
	int i = p, j = p + 1;//i记录比x小的末位，j记录当前要比较的值
	while (j<=r) {
		if ((a[j]<x) && (++i != j)) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		j++;
	}
	temp = a[i];
	a[i] = a[p];
	a[p] = temp;
	return i;
}

//
//8 9 10  12 13 14
//
//11

