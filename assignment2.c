#include <stdio.h>
void main()
{
    int temp,j,i,a[10],n,k;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("\nenter %d elements: ",n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    printf("\nenter k value:");
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        temp=a[n-1];
        for(j=n-2;j>=0;j--)
        {
            a[j+1]=a[j];
        }
        a[0]=temp;
    }
    for(i=0;i<n;i++)
     printf("%d ",a[i]);
}

