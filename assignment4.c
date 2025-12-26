
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int data;
}NODE;
NODE *f1=NULL,*f2=NULL,*temp,*cur,*a,*b;
int item;
void insertrearf1(int item)
{   
    temp=(NODE*)malloc(sizeof(NODE));
    temp->next=NULL;
    temp->data=item;

    if(f1==NULL)
    {
        f1=temp;
        return;
    }
    cur=f1;
    while(cur->next!=NULL)
     cur=cur->next;
    cur->next=temp;
}
void insertrearf2(int item)
{   
    temp=(NODE*)malloc(sizeof(NODE));
    temp->next=NULL;
    temp->data=item;

    if(f2==NULL)
    {
        f2=temp;
        return;
    }
    cur=f2;
    while(cur->next!=NULL)
     cur=cur->next;
    cur->next=temp;
}

void concatinate()
{
    cur=f1;
    while(cur->next!=NULL)
     cur=cur->next;
    cur->next=f2;
}

NODE* sort()
{   int t;
    for(a=f1;a!=NULL;a=a->next)
    {
     for(b=a->next;b!=NULL;b=b->next)
     {
        if(a->data>b->data)
        {
          t=a->data;
          a->data=b->data;
          b->data=t;
        }
     }
    }
    
  return f1;      
}
int main()
{ 
    int n1,n2,i;
    printf("\nenter number of nodes in 1st and 2nd SLL");
    scanf("%d%d",&n1,&n2);
    printf("\nenter 1st SLL sorted elements");
    for(i=0;i<n1;i++)
    {
     printf("\nenter element:");
     scanf("%d",&item);
     insertrearf1(item);
    }
     printf("\nenter 2st SLL sorted elements");
    for(i=0;i<n2;i++)
    {
     printf("\nenter element:");
     scanf("%d",&item);
     insertrearf2(item);
    }
    concatinate();
    printf("\nsorted SLL:\n");
    for(cur=sort();cur!=NULL;cur=cur->next)
     printf("%d->",cur->data);
    printf("NULL");
    return 0;
}

