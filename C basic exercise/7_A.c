#include<stdio.h>
#include<string.h>
char *locatesubstr(char *str1,char *str2);
int main(){
	char str1[510],str2[510];
	gets(str1);
	gets(str2);
	puts(locatesubstr(str1,str2));
	return 0;
}
char *locatesubstr(char *str1,char *str2){
	char *p2,*p1;
	while (*str1!='\0'){
		p1=str1;
		if (*p1==*str2){
			p2=str2;
			while ((*p1==*p2)) {
				p1++;p2++;
			}
			p1--;
			//���ܳ������������1.����string������ĩβ����ʱp2��ǰһλ����\0�����ڴ�p1--���ж�p1;
			//2.ֻ��p2����ĩβ����ʱp2Ϊ\0 
			if ((*p2=='\0')||(*p1=='\0')) return str1; 
		}
		str1++;
	}
	return "NULL!";
}
