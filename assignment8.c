#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
} NODE;

NODE *last = NULL, *temp, *cur, *nextt, *prev;
int item;

void insertrear(int item)
{
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = NULL;

    if (last == NULL)
    {
        last = temp;
        last->next = last;
    }
    else if (last->next == last)
    {
        last->next = temp;
        temp->next = last;
        last = temp;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void duplicates()
{
    if (last == NULL || last->next == last)
        return;

    cur = last->next;

    do
    {
        prev = cur;
        temp = cur->next;

        while (temp != last->next)
        {
            if (temp->data == cur->data)
            {
                if (temp == last)
                    last = prev;

                prev->next = temp->next;
                nextt = temp;
                temp = prev->next;
                free(nextt);
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        cur = cur->next;

    } while (cur != last);
}

int main()
{
    int n, i;

    printf("\nenter number of nodes in CSLL:");
    scanf("%d", &n);

    printf("\nenter %d CSLL elements:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        insertrear(item);
    }

    duplicates();

    if (last != NULL)
    {
        for (cur = last->next; cur != last; cur = cur->next)
        {
            printf("%d->", cur->data);
        }
        printf("%d", last->data);
    }

    return 0;
}
