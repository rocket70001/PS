#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int order;
    struct _node *next;
    struct _node *prev;
} node;

typedef struct _list {
    node *cur;
    node *tail;
    int total;
} list;

void init(list *li)
{
    li->cur = NULL;
    li->tail = NULL;
    li->total = 0;
}
void insertR(list *li, int data)
{
    node *new_node = (node*)malloc(sizeof(node));

    new_node -> order = data;
    if(li -> total == 0)
    {
        new_node -> prev = new_node;
        new_node -> next = new_node;
        li -> cur = new_node;
        li -> tail = new_node;
    }
    else if(li -> total == 1)
    {
        new_node -> prev = li -> cur;
        new_node -> next = li -> tail;
        li -> tail -> prev = new_node;
        li -> tail -> next = new_node;
        li -> cur = new_node;
    }
    else
    {
        new_node -> prev = li -> cur;
        new_node -> next = li -> tail;
        li -> cur -> next = new_node;
        li -> tail -> prev = new_node;
        li -> cur = new_node;
    }
    li -> total++;
}

int pop_in_order(list *li, int times)
{
    if (li->total == 0)
        return -1;
    for (int i = 1; i < times % li->total; i++)
        li->cur = li->cur->next;
    node *pop_node = li->cur;
    int pop_int = li->cur->order;
    li->cur->prev->next = li->cur->next;
    li->cur->next->prev = li->cur->prev;
    if (pop_node == li->tail) {
        if (li->total == 1)
            li->tail = NULL;
        else {
            li->tail = li->cur->next;
            li->tail->next = li->cur->next->next;
            li->tail->prev = li->cur->prev;
        }
    }
    li->total--;
    li->cur = li->cur->next;
    free(pop_node);
    return pop_int;
}

int main()
{
    int n, times;
    list *circle = (list *)malloc(sizeof(list));
    if (scanf("%d %d", &n, &times) != 2) {
        printf("Invalid input\n");
        exit(1);
    }
    init(circle);
    for (int i = 1; i <= n; i++)
        insertR(circle, i);
    circle->cur = circle->tail;
    printf("<");
    for (int i = 0; i < n - 1; i++)
        printf("%d, ", pop_in_order(circle, times));
    printf("%d>", pop_in_order(circle, times));
    free(circle);
    return 0;
}
