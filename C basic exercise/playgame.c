#include<stdio.h>
int del(int enegy[], int n, int m); //现有的能量数， 人数 
void sort(int enegy[], int n);
int main() {
	int n, m, i;
	int enegy[10000] = { 0 };
	scanf_s("%d%d", &n, &m);
	for (i = 0; i<n; i++) scanf_s("%d", &enegy[i]);
	sort(enegy, n);
	//多余的数删除 
	if (n>m) {
		for (i = m; i<n; i++) enegy[i] = 0;
		n = m;
	}
	//判断是否删除末尾数 
	int temp = del(enegy, n, m);
	printf("%d", temp);
	system("pause");
	return 0;
}
int del(int enegy[], int n, int m) {
	int i, k, j, flag = 0, count = 0, p = 1;
	//m-1为基准
	for (i = 0; i<n - 2; i++) {
		k = enegy[i] / (enegy[n - 1] + 1) - 1;
		if (k < 1) break;
		count += k;
	}
	if (count >= m - n + 1) {
		return del(enegy, n - 1, m);
		flag = 1;
	}
	count = 0;
	if (flag == 0) {
		//找最小值能给多少人充电,p
		while (p <= m) {
			count = 0;
			for (i = 0; i<n; i++) {
				count += enegy[i] / (enegy[n - 1] / p);
			}
			if (count<m) p++; else break;
		}
		count = 0;
		//介于p-1和p之间
		int res1 = enegy[n - 1] / p;
		int res2 = enegy[n - 1] / (p - 1);
		int result;
		for (i = res1; i <= res2; i++) {
			count = 0;
			for (j = 0; j<n; j++) 
				count += enegy[j] / i;
			if (count<m) {
				result = i - 1;
				break;
			}
			else if (count == m) {
				result = i;
				break;
			}
		}
		return result;
	}
}

void sort(int enegy[], int n) {
	int i, j, temp;
	for (i = 0; i<n; i++)
		for (j = 1; j<n - i; j++)
			if (enegy[j - 1]<enegy[j]) {
				temp = enegy[j - 1];
				enegy[j - 1] = enegy[j];
				enegy[j] = temp;
			}
	for (i = 0; i<n; i++) i != n - 1 ? printf("%d ", enegy[i]) : printf("%d\n", enegy[i]);
}




