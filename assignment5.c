
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;
NODE *first,*temp,*cur,*pre;
int item;

void insertrear(int item)
{   
    temp=(NODE*)malloc(sizeof(NODE));
    temp->next=temp->prev=NULL;
    temp->data=item;

    if(first==NULL)
    {
        first=temp;
        return;
    }
    cur=first;
    while(cur->next!=NULL)
     cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
}

void move()
{
    pre=NULL;
    cur=first;
    while(cur->next!=NULL)
    {
        
     pre=cur;
     cur=cur->next;
    }
    pre->next=cur->prev=NULL;
    cur->next=first;
    first->prev=cur;
    first=cur;
    
}


int main()
{   int i,n;
    printf("enter number of nodes:");
    scanf("%d",&n);
    printf("\nenter %d elements:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        insertrear(item);
    }
    move();
    for(cur=first;cur!=NULL;cur=cur->next)
    { printf("%d",cur->data);
      if(cur->next!=NULL)
       printf("->");
    }

    return 0;
}
