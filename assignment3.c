#include <stdio.h>

int main()
{
    int a[10],n=0,i,j;
    printf("enter number of array elements:");
    scanf("%d",&n);
    printf("enter array elements:");
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    j=n/2;
    for(i=0;i<=(n/2)-1;i++)
    {
     printf("%d ",a[i]);
     for(;j<=n;)
     {
     printf("%d ",a[j]);
     break;    
     }
     j++;
    }

    return 0;
}
