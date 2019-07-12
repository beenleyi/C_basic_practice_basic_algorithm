#include<stdio.h>
#include<stdlib.h>
char * *   f(int );
main()
{
   char * *ptr;
   int i;
   ptr=f(100);
   for(i=0;i<=4;i++)
      gets(*(ptr+i));
   for(i=0;i<=4;i++)
      puts(*(ptr+i));
   return 0;
}

char ** f(int length)
{
    int i;
    char  **a;
	a=(char **)malloc (sizeof(char*)*5); 
    for(i=0;i<=4;i++)
    a[i]=malloc(sizeof(char)*length);
    return a;
} 

