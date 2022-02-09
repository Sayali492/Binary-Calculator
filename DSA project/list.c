#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bcalc.h"
#include "list.h"
#include "stack.h"


void init_list(list *L)
{
          *L = NULL;
          return;
}
void append(list *L, int d)
{
          struct node *p;
          p = *L;
          if (p == NULL)
          {
                    p = (struct node *)malloc(sizeof(struct node));
                    p->data = d;
                    p->next = NULL;
                    *L = p;
          }
          else
          {
                    while (p->next != NULL)
                    { 
                              p = p->next;
                    }
                    p->next = (struct node *)malloc(sizeof(struct node));
                    p->next->data = d;
                    p->next->next = NULL;
          }
}

void insert_begin(list *L, int d, int place)
{ 
          int ind = 1;
          node *q;
          q = (struct node *)malloc(sizeof(struct node));
          if (q == NULL)
                    return;
          else
          {
                    q->data = d;
                    q->index = place;
                    q->next = *L;
                    *L = q;

                    return;
          }
}
node *delete_a_node(list *L, int d, int pos)
{
          struct node *p, *q;
          int count;
          p = *L;
          q = NULL;
          if (p == NULL)
          {
                    return *L;
          }
          while (p != NULL)
          {
                    count++;
                    p = p->next;
          }
          p = *L;
          if (count == 1)
          {

                    while (p && p->data != d)
                    {
                              q = p;
                              p = p->next;
                    }
                    if (p != NULL)
                    {
                              *L = NULL;
                              free(p);
                    }
                    else
                    {
                              return *L;
                    }
          }
          if (count > 1 && pos == 1)
          {
                    while (p && p->data != d)
                    {
                              q = p;
                              p = p->next;
                    }
                    if (p != NULL)
                    {
                              *L = p->next;
                              free(p);
                    }
                    else
                    {
                              return *L;
                    }
          }
          else if (count > 1 && pos != 1)
          {
                    while (p && p->data != d)
                    {
                              q = p;
                              p = p->next;
                    }
                    if (p != NULL)
                    {
                              q->next = p->next;
                              free(p);
                    }
                    else
                    {
                              return *L;
                    }
          }
          return *L;
}
node_char *delete_a_charnode(char_list *L, char d, int pos)
{
          node_char *p, *q;
          int count;
          p = *L;
          q = NULL;
          if (p == NULL)
          {
                    return *L;
          }
          while (p != NULL)
          {
                    count++;
                    p = p->next;
          }
          p = *L;
          if (count == 1)
          {

                    while (p && p->ch != d)
                    {
                              q = p;
                              p = p->next;
                    }
                    if (p != NULL)
                    {
                              *L = NULL;
                              free(p);
                    }
                    else
                    {
                              return *L;
                    }
          }
          if (count > 1 && pos == 1)
          {
                    while (p && p->ch != d)
                    {
                              q = p;
                              p = p->next;
                    }
                    if (p != NULL)
                    {
                              *L = p->next;
                              free(p);
                    }
                    else
                    {
                              return *L;
                    }
          }
          else if (count > 1 && pos != 1)
          {
                    while (p && p->ch != d)
                    {
                              q = p;
                              p = p->next;
                    }
                    if (p != NULL)
                    {
                              q->next = p->next;
                              free(p);
                    }
                    else
                    {
                              return *L;
                    }
          }
          return *L;
}

node *reverse_list(list *L)
{
          struct node *prev = NULL;
          struct node *current = *L;
          struct node *p = NULL;
          while (current != NULL)
          {

                    p = current->next;

                    current->next = prev;

                    prev = current;
                    current = p;
          }
          *L = prev;
          return *L;
}

int compare_lists(list La, list Lb)
{
          int cnt1 = 0, cnt2 = 0, res = 0;
          node *p, *q;
          p = La;
          q = Lb;
          while (p->next != NULL)
          {
                    p = p->next;
          }
          cnt1 = p->index;
          while (q->next != NULL)
          {
                    q = q->next;
          }
          cnt2 = q->index;
          p = La;
          q = Lb;
          if (cnt1 > cnt2)
                    return 1;
          if (cnt2 > cnt1)
                    return 2;
          if (cnt1 == cnt2)
          {
                    while (p != NULL)
                    {
                              if (p->data > q->data)
                              {
                                        res = 1;
                                        p = NULL;
                              }
                              else if (p->data < q->data)
                              {
                                        res = 2;
                                        p = NULL;
                              }
                              else
                              {
                                        p = p->next;
                                        q = q->next;
                              }
                    }
          }
          return res;
}


node *remove_trailing_zeroes(list *L)
{

          node *p, *q, *r, *reverse, *final;
          p = *L;
          reverse = reverse_list(&p);
          q = reverse;
          while (q->data == 0)
          {
                    r = q;
                    reverse = q->next;
                    q = q->next;
                    r->next = NULL;
          }
          final = reverse_list(&reverse);
          return final;
}


int display_num_int(list L)
{
          int num = 0;
          node *p;
          p = L;
          while (p != NULL)
          {
                    num = num + p->data * (pow(10, p->index));
                    p = p->next;
          }
          return num;
}
void display_num(list L)
{

          node *res;
          int i = 0;
          res = reverse_list(&L);
          while (res != NULL)
          {
                    if(res->next!=NULL){
                              if(res->data<0){
                                        printf("%d", -(res->data));
                                        res=res->next;
                              }
                              else{
                                        printf("%d", res->data);
                                        res=res->next;
                              }
                    }
                    else{
                    printf("%d", res->data);
                    res = res->next;
                    }
          }
          
}
void display_New_List(List L)
{

          Node *p, *res;

          node *q;
          p = L;

          while (p != NULL)
          {
                    // printf("Index1 %d\n", p->index1);
                    q = p->down;
                    while (q != NULL)
                    {
                              printf("%d\n", q->data);
                              q = q->next;
                    }
                    printf("\n");
                    p = p->right;
          }
}
