#include <stdio.h>
#include <algorithm>
using namespace std;
int i,j,T,M,t[10001],p[10001],f[100001]={0};
int main()
{
    scanf("%d%d",&T,&M);
    for(i=1;i<=M;i++)
        scanf("%d%d",&t[i],&p[i]);
    for(i=1;i<=M;i++)
        {
        	for(j=t[i];j<=T;j++)
            {
            	f[j]=max(f[j],f[j-t[i]]+p[i]);//µÝÍÆ
            //	printf("%d ",f[j]);
			}
		//	printf("\n");
		}
    printf("%d",f[T]);
    return 0;
}
