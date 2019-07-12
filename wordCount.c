#include<stdio.h>
int main(){
	char str[200];
	gets(str);
	char c;
	int word=0,i=0,num=0;
	while (str[i]!='\0'){
		if (str[i]==' ') word=0;
		else 
			if (word==0) {
				num++;
				word=1;
		}
		i++;
	}
	printf("%d",num);
	return 0;
}

