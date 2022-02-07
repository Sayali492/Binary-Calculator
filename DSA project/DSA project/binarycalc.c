#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
          int data;
          int index;
          struct node *next;

} node;
typedef struct node *list;

typedef struct node_char
{
          char ch;
          int index;
          struct node_char *next;

} node_char;
typedef node_char *char_list;

typedef struct node1
{
          int index1;
          struct node1 *right;
          struct node *down;
} Node;
typedef Node *List;

Node *reverse_List(List L)
{
          Node *prev = NULL;
          Node *current = L;
          Node *p = NULL;
          while (current != NULL)
          {

                    p = current->right;

                    current->right = prev;

                    prev = current;
                    current = p;
          }
          L = prev;
          return L;
}
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
                    { // alert:write p->next!=null and not p!=NULL
                              p = p->next;
                    }
                    p->next = (struct node *)malloc(sizeof(struct node));
                    p->next->data = d;
                    p->next->next = NULL;
          }
}

void insert_begin(list *L, int d, int place)
{ // here first I had done struct node *L,but it didnt give any op,coz I passed its value.Pass the arguments by reference and then u get the op.
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
void destroy_List(list L)
{
          /* deref head_ref to get the real head */
          node *p = L;
          node *q;

          while (p != NULL)
          {
                    L = p->next;
                    q = p;
                    p = p->next;
                    q->next = NULL;
                    //        q = p->next;
                    //        free(p);
                    //        p = q;
          }
          p = L;
          p->next = NULL;
          L = NULL;
}
void print_nodes(struct node *L)
{
          struct node *p;
          p = L;
          if (L == NULL)
                    printf("List is Empty");
          while (p != NULL)
          {
                    printf("%d %d\n", p->data, p->index);
                    p = p->next;
          }
          printf("\n");
}
// stack using array
typedef struct stack
{
          int size;
          int top;
          int *A;

} stack;
void init_stack(stack *S, int s)
{
          S->size = s;
          S->top = -1;
          S->A = (int *)malloc(sizeof(int) * s);
          return;
}

int is_stack_empty(stack S)
{
          if (S.top == -1)
                    return 1;
          else
                    return 0;
}
int is_stack_full(stack S)
{
          if (S.top == S.size - 1)
                    return 1;
          else
                    return 0;
}
void push(stack *S, int d)
{
          if (S->top == -1)
          {
                    S->top++;
                    S->A[S->top] = d;
                    return;
          }
          else if (is_stack_full(*S))
                    return;
          else
          {
                    S->top++;
                    S->A[S->top] = d;
                    return;
          }
}

int pop(stack *S)

{
          long int num;
          num = INT_MIN;
          if (is_stack_empty(*S))
                    return num;
          else
          {

                    int x;
                    x = S->A[S->top];
                    S->top--;
                    return x;
          }
}

int peak(stack S)
{
          long int num;
          num = INT_MIN;
          if (is_stack_empty(S))
                    return num;
          else
          {
                    int x;
                    x = S.A[S.top];

                    return x;
          }
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
void precedence(char_list L, list *array, int count_no)
{
          node_char *p;
          node *q;
          *array = NULL;
          int i = 0;
          p = L;
          while (p != NULL)
          {

                    switch (p->ch)
                    {
                    case '+':
                    case '-':
                              if (*array == NULL)
                              {
                                        *array = (node *)malloc(sizeof(node));
                                        q = *array;
                                        q->data = 1;
                                        q->index = i;
                                        q->next = NULL;
                                        i++;
                              }
                              else
                              {
                                        q = *array;
                                        while (q->next != NULL)
                                        {
                                                  q = q->next;
                                        }
                                        q->next = (node *)malloc(sizeof(node));
                                        q = q->next;
                                        q->data = 1;
                                        q->index = i;
                                        q->next = NULL;
                                        i++;
                              }

                              break;
                    case '*':
                    case '/':
                    case '%':
                              if (*array == NULL)
                              {
                                        *array = (node *)malloc(sizeof(node));
                                        q = *array;
                                        q->data = 2;
                                        q->index = i;
                                        q->next = NULL;
                                        i++;
                              }
                              else
                              {
                                        q = *array;
                                        while (q->next != NULL)
                                        {
                                                  q = q->next;
                                        }
                                        q->next = (node *)malloc(sizeof(node));
                                        q = q->next;
                                        q->data = 2;
                                        q->index = i;
                                        q->next = NULL;
                                        i++;
                              }
                              break;
                    case '^':
                              if (*array == NULL)
                              {
                                        *array = (node *)malloc(sizeof(node));
                                        q = *array;
                                        q->data = 3;
                                        q->index = i;
                                        q->next = NULL;
                                        i++;
                              }
                              else
                              {
                                        q = *array;
                                        while (q->next != NULL)
                                        {
                                                  q = q->next;
                                        }
                                        q->next = (node *)malloc(sizeof(node));
                                        q = q->next;
                                        q->data = 3;
                                        q->index = i;
                                        q->next = NULL;
                                        i++;
                              }
                              break;
                    }
                    p = p->next;
          }
          // for(i=0;i<count_no;i++){
          //           printf("%d\n",array[i]);
          // }
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
                    printf("%d %d\n", res->data, res->index);
                    res = res->next;
          }
          // node *p;
          // p = res;
          // while (p != NULL)
          // {
          //         str[i]=p->data-'0';

          //         p = p->next;
          //         i++;
          // }
          // return str;
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

node *init(char *str, int cnt, int total_cnt)
{
          int i = 0, ind = 0, k = 0, j = 0;
          list arr[cnt + 1];
          int op_arr[cnt];
          list L1;
          init_list(&L1);
          stack S1;
          init_stack(&S1, 1000);
          char op[50];

          while (i < total_cnt)
          {
                    while (str[i] >= '0' && str[i] <= '9')
                    {
                              push(&S1, str[i] - '0');
                              i++;
                    }
                    arr[k] = (node *)malloc(sizeof(node));
                    arr[k]->data = pop(&S1);
                    arr[k]->index = ind;
                    ind++;
                    arr[k]->next = NULL;
                    node *p;
                    p = arr[k];
                    while (!(is_stack_empty(S1)))
                    {

                              p->next = (node *)malloc(sizeof(node));
                              p = p->next;
                              p->data = pop(&S1);
                              p->index = ind;
                              ind++;
                              p->next = NULL;
                    }
                    ind = 0;
                    op[j] = str[i];
                    j++;
                    k++;

                    i++;
          }
          return *arr;
}

node *addition(list La, list Lb)
{
          struct node *p, *q, *r;
          list P3;

          int i = 0, count = 0, sum, carry = 0, cnt1 = 0, cnt2 = 0;

          init_list(&P3);

          P3 = (node *)malloc(sizeof(node));
          r = P3;
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
          if (cnt1 == cnt2)
          {

                    while (p != NULL)
                    {

                              sum = carry + p->data + q->data;
                              if (sum >= 10)
                              {
                                        r->data = sum - 10;
                                        carry = sum / 10;
                              }
                              else
                              {

                                        r->data = sum;
                                        carry = 0;
                              }
                              r->index = p->index;
                              r->next = NULL;
                              if (p->next == NULL)
                              {
                                        if (carry != 0)
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                                  r->data = carry;
                                                  r->index = cnt1 + 1;
                                                  r->next = NULL;
                                        }
                                        else
                                                  r->next = NULL;
                              }
                              else
                              {
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                              }
                              p = p->next;
                              q = q->next;
                    }
          }
          else if (cnt1 > cnt2)
          {
                    while (p != NULL)
                    {
                              while (q != NULL)
                              {
                                        sum = carry + p->data + q->data;
                                        if (sum >= 10)
                                        {
                                                  r->data = sum - 10;
                                                  carry = sum / 10;
                                        }
                                        else
                                        {

                                                  r->data = sum;
                                                  carry = 0;
                                        }
                                        r->index = p->index;
                                        r->next = NULL;
                                        if (p->next == NULL)
                                        {
                                                  if (carry != 0)
                                                  {
                                                            r->next = (node *)malloc(sizeof(node));
                                                            r = r->next;
                                                            r->data = carry;
                                                            r->index = cnt1 + 1;
                                                            r->next = NULL;
                                                  }
                                                  else
                                                            r->next = NULL;
                                        }
                                        else
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        p = p->next;
                                        q = q->next;
                              }
                              sum = p->data + carry;
                              if (sum >= 10)
                              {
                                        r->data = sum - 10;
                                        carry = sum / 10;
                              }
                              else
                              {

                                        r->data = sum;
                                        carry = 0;
                              }
                              r->index = p->index;
                              r->next = NULL;
                              if (p->next == NULL)
                              {
                                        if (carry != 0)
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                                  r->data = carry;
                                                  r->index = cnt1 + 1;
                                                  r->next = NULL;
                                        }
                                        else
                                                  r->next = NULL;
                              }
                              else
                              {
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                              }
                              p = p->next;
                    }
          }
          else
          {
                    while (q != NULL)
                    {
                              while (p != NULL)
                              {
                                        sum = carry + p->data + q->data;
                                        if (sum >= 10)
                                        {
                                                  r->data = sum - 10;
                                                  carry = sum / 10;
                                        }
                                        else
                                        {

                                                  r->data = sum;
                                                  carry = 0;
                                        }
                                        r->index = q->index;
                                        r->next = NULL;
                                        if (q->next == NULL)
                                        {
                                                  if (carry != 0)
                                                  {
                                                            r->next = (node *)malloc(sizeof(node));
                                                            r = r->next;
                                                            r->data = carry;
                                                            r->index = cnt2 + 1;
                                                            r->next = NULL;
                                                  }
                                                  else
                                                            r->next = NULL;
                                        }
                                        else
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        p = p->next;
                                        q = q->next;
                              }
                              sum = q->data + carry;
                              if (sum >= 10)
                              {
                                        r->data = sum - 10;
                                        carry = sum / 10;
                              }
                              else
                              {

                                        r->data = sum;
                                        carry = 0;
                              }
                              r->index = q->index;
                              r->next = NULL;
                              if (q->next == NULL)
                              {
                                        if (carry != 0)
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                                  r->data = carry;
                                                  r->index = cnt1 + 1;
                                                  r->next = NULL;
                                        }
                                        else
                                                  r->next = NULL;
                              }
                              else
                              {
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                              }
                              q = q->next;
                    }
          }

          r = P3;
          return P3;
          // while (r != NULL)
          // {
          //         printf("%d %d\n", r->data, r->index);
          //         r=r->next;
          // }
}

node *subtraction(list La, list Lb)
{
          struct node *p, *q, *r, **ptr, *res, *result;

          int num1, num2, i = 0, count = 0, diff, borrow = 0, cnt1 = 0, cnt2 = 0, comp;
          num1 = display_num_int(La);
          num2 = display_num_int(Lb);
          list P3;
          init_list(&P3);
          comp = compare_lists(La, Lb);
          if (comp == 0)
          {
                    result = (node *)malloc(sizeof(node));
                    result->data = 0;
                    result->index = 0;
                    result->next = NULL;
                    return result;
          }

          P3 = (node *)malloc(sizeof(node));
          r = P3;
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
          if (cnt1 == cnt2)
          {
                    while (p != NULL)
                    {
                              if (num1 >= num2)
                              {
                                        diff = p->data - q->data;
                                        if (diff >= 0)
                                        {
                                                  r->data = diff;
                                        }
                                        else
                                        {
                                                  p->next->data -= 1;
                                                  p->data = 10 + p->data;
                                                  diff = p->data - q->data;
                                                  r->data = diff;
                                        }
                                        r->index = p->index;
                                        r->next = NULL;
                                        if (p->next == NULL)
                                        {
                                                  r->next = NULL;
                                        }
                                        else
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        p = p->next;
                                        q = q->next;
                              }
                              else
                              {
                                        diff = q->data - p->data;
                                        if (diff >= 0)
                                        {
                                                  r->data = diff;
                                        }
                                        else
                                        {
                                                  q->next->data -= 1;
                                                  q->data = 10 + q->data;
                                                  diff = q->data - p->data;
                                                  r->data = diff;
                                        }
                                        r->index = q->index;
                                        r->next = NULL;
                                        if (q->next == NULL)
                                        {
                                                  r->next = NULL;
                                        }
                                        else
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        p = p->next;
                                        q = q->next;
                              }
                    }
          }
          else if (cnt1 > cnt2)
          {

                    while (p != NULL)
                    {
                              while (q != NULL)
                              {
                                        diff = p->data - q->data;
                                        if (diff >= 0)
                                        {
                                                  r->data = diff;
                                        }
                                        else
                                        {
                                                  p->next->data -= 1;
                                                  p->data = 10 + p->data;
                                                  diff = p->data - q->data;
                                                  r->data = diff;
                                        }
                                        r->index = p->index;
                                        r->next = NULL;
                                        if (p->next == NULL)
                                        {
                                                  r->next = NULL;
                                        }
                                        else
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        p = p->next;
                                        q = q->next;
                              }
                              diff = p->data;
                              r->data = diff;
                              r->index = p->index;
                              if (p->next == NULL)
                              {
                                        r->next = NULL;
                              }
                              else
                              {
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                              }
                              p = p->next;
                    }
          }
          else
          {
                    while (q != NULL)
                    {
                              while (p != NULL)
                              {
                                        diff = q->data - p->data;
                                        if (diff >= 0)
                                        {
                                                  r->data = diff;
                                        }
                                        else
                                        {
                                                  q->next->data -= 1;
                                                  q->data = 10 + q->data;
                                                  diff = q->data - p->data;
                                                  r->data = diff;
                                        }
                                        r->index = q->index;
                                        r->next = NULL;
                                        if (q->next == NULL)
                                        {
                                                  r->next = NULL;
                                        }
                                        else
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        p = p->next;
                                        q = q->next;
                              }
                              diff = q->data;
                              r->data = diff;
                              r->index = q->index;
                              if (q->next == NULL)
                              {
                                        r->next = NULL;
                              }
                              else
                              {
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                              }
                              q = q->next;
                    }
          }
          r = P3;
          if (r->next == NULL)
          {
                    comp = compare_lists(La, Lb);
                    if (comp == 2)
                    {
                              r = P3;
                              while (r->next != NULL)
                              {
                                        r = r->next;
                              }
                              r->data = -(r->data);
                    }
                    if (comp == 0)
                    {
                              P3 = (node *)malloc(sizeof(node));
                              P3->data = 0;
                              P3->index = 0;
                              P3->next = NULL;
                    }

                    return P3;
          }
          else
          {

                    res = remove_trailing_zeroes(&P3);
                    r = res;
                    comp = compare_lists(La, Lb);
                    if (comp == 2)
                    {
                              r = P3;
                              while (r->next != NULL)
                              {
                                        r = r->next;
                              }
                              r->data = -(r->data);
                    }
                    // if (comp == 0)
                    // {
                    //           result = (node *)malloc(sizeof(node));
                    //           result->data = 0;
                    //           result->index = 0;
                    //           result->next = NULL;
                    //           return result;
                    // }
                    r = res;
                    return res;
          }
}

node *multiplication(node *La, node *Lb)
{

          node *p, *q, *r, *res;

          int num, i = 0, k = 0, count = 0, multiply, carry = 0, cnt1 = 0, cnt2 = 0, j = 0, m, ind = 0, zero = 0;
          //  printf("Lb\n");
          // p = Lb;
          // while (p != NULL)
          // {
          //           printf("%d %d\n", p->data, p->index);
          //           p = p->next;
          // }
          // printf("\n");
          // printf("La\n");
          // p = La;
          // while (p != NULL)
          // {
          //           printf("%d %d\n", p->data, p->index);
          //           p = p->next;
          // }
          // printf("\n");
          list P3;

          p = La;
          q = Lb;
          while (q != NULL)
          {
                    if (q->data != 0)
                              zero = 1;
                    q = q->next;
          }
          if (zero == 0)
          {
                    P3 = (node *)malloc(sizeof(node));
                    P3->data = 0;
                    P3->index = 0;
                    P3->next = NULL;
                    return P3;
          }
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
          int min = cnt1;
          if (min > cnt2)
                    min = cnt2;
          list multi[min + 1];
          // multi[i] = (node *)malloc(sizeof(node));
          // r = multi[i];
          p = La;
          q = Lb;
          if (cnt1 >= cnt2)
          {

                    while (q != NULL)

                    {
                              p = La;
                              multi[i] = (node *)malloc(sizeof(node));
                              r = multi[i];
                              for (m = 0; m < j; m++)
                              {
                                        r->data = 0;
                                        r->index = ind;
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                                        ind++;
                              }

                              while (p != NULL)
                              {

                                        multiply = (q->data * p->data) + carry;
                                        num = multiply % 10;
                                        carry = multiply / 10;

                                        if (p->next == NULL)
                                        {
                                                  if (multiply >= 10)
                                                  {
                                                            r->data = num;
                                                            r->index = ind;
                                                            // ind++;
                                                            r->next = (node *)malloc(sizeof(node));
                                                            r = r->next;
                                                            r->data = carry;
                                                            r->index = ind;
                                                            ind++;
                                                            r->next = NULL;
                                                  }
                                                  else
                                                            r->data = multiply;
                                        }
                                        else
                                                  r->data = num;
                                        r->index = ind;
                                        r->next = NULL;
                                        if (p->next != NULL)
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        ind++;

                                        p = p->next;
                              }
                              q = q->next;
                              j++;
                              i++;

                              carry = 0;
                              ind = 0;
                              // if (i == 2)
                              // {
                              //         res = addition(multi[0], multi[1]);
                              //         while (res != NULL)
                              //         {
                              //                 printf("%d %d\n", res->data, res->index);
                              //                 res = res->next;
                              //         }
                              // }
                    }
          }
          else
          {
                    while (p != NULL)
                    {
                              q = Lb;
                              multi[i] = (node *)malloc(sizeof(node));
                              r = multi[i];
                              for (m = 0; m < j; m++)
                              {
                                        r->data = 0;
                                        r->index = ind;
                                        r->next = (node *)malloc(sizeof(node));
                                        r = r->next;
                                        ind++;
                              }

                              while (q != NULL)
                              {

                                        multiply = (q->data * p->data) + carry;
                                        num = multiply % 10;
                                        carry = multiply / 10;

                                        if (q->next == NULL)
                                                  if (multiply >= 10)
                                                  {
                                                            r->data = num;
                                                            r->index = ind;
                                                            ind++;
                                                            r->next = (node *)malloc(sizeof(node));
                                                            r = r->next;
                                                            r->data = carry;
                                                            r->index = ind;
                                                            ind++;
                                                            r->next = NULL;
                                                  }
                                                  else
                                                            r->data = multiply;
                                        else
                                                  r->data = num;
                                        r->index = ind;
                                        r->next = NULL;
                                        if (q->next != NULL)
                                        {
                                                  r->next = (node *)malloc(sizeof(node));
                                                  r = r->next;
                                        }
                                        ind++;
                                        q = q->next;
                              }
                              p = p->next;
                              i++;
                              j++;
                              carry = 0;
                              ind = 0;
                    }
          }

          p = multi[0];
          if (min == 0)
          {
                    while (p != NULL)
                    {
                              if (p->data >= 10)
                              {
                                        num = p->data % 10;
                                        carry = p->data / 10;
                                        p->data = num;
                                        ind = p->index;
                                        p->next = (node *)malloc(sizeof(node));

                                        p = p->next;
                                        p->data = carry;
                                        p->index = ind + 1;
                                        p->next = NULL;
                              }
                              else
                                        p = p->next;
                    }
                    return multi[0];
          }
          else
          {
                    res = addition(multi[k], multi[k + 1]);
                    k = k + 2;
                    for (i = 1; i < min; i++)
                    {
                              res = addition(res, multi[k]);
                              k++;
                    }
          }
          p = res;
          while (p != NULL)
          {
                    if (p->data >= 10)
                    {
                              num = p->data % 10;
                              carry = p->data / 10;
                              p->data = num;
                              p->next = (node *)malloc(sizeof(node));
                              q = p;
                              p = p->next;
                              p->data = carry;
                              p->index = q->index + 1;
                              p->next = NULL;
                    }
                    else
                              p = p->next;
          }

          return res;
}
// p = multi[0];
// q = multi[1];
// while (p != NULL)
// {
//         printf("%d %d\n", p->data, p->index);
//         p = p->next;
// }
// while (q != NULL)
// {
//         printf("%d %d\n", q->data, q->index);
//         q = q->next;
// }
// return multi[0];

// int division(list La, list Lb)
// {

//           long long int num1, num2;
//           int cnt = 0, cnt1 = 0, cnt2 = 0, i = 9,j=1;
//           // num2 = display_num_int(Lb);
//           // num1=display_num_int(La);

//           list L;
//           L = (node *)malloc(sizeof(node));
//           L->data = i;
//           L->index = 0;
//           L->next = NULL;
//           node *p, *q, *diff, *multi, *ptr1;
// p=La;
// q=Lb;
// while (p != NULL)
// {
//           printf("%d %d\n", p->data, p->index);
//           p = p->next;
// }
// while (q != NULL)
// {
//           printf("%d %d\n", q->data, q->index);
//           q = q->next;
// }
// p = La;
// q = Lb;
// while (p->next != NULL)
// {
//           p = p->next;
// }
// cnt1 = p->index;
// while (q->next != NULL)
// {
//           q = q->next;
// }
// cnt2 = q->index;
// p = La;
// q = Lb;
// char string[1000];

// int count = 0, comp;
// int total_cnt = 1;
// printf("%d %d \n", cnt1, cnt2);

// if (cnt1 > cnt2)
// {
//         num1 = 2;
//         num2 = 1;
// }
// else if (cnt1 == cnt2)
// {
//         while (p != NULL)
//         {
//                 if (p->data > q->data)
//                 {
//                         num1 = 2;
//                         num2 = 1;
//                         p = NULL;
//                 }
//                 else if (p->data == q->data)
//                 {
//                         p = p->next;
//                         q = q->next;
//                 }
//                 else
//                 {
//                         cnt = 0;
//                         return cnt;
//                 }
//         }
// }
// else
// {
//         return cnt;
// }
// while (i > -1)
// {
// itoa(i, string, 10);
// int j = 0;
// // printf("%s",string);
// L = init(string, count, total_cnt);
//           L->data = i;

//           multi = multiplication(Lb, L);
//           // display_num(multi);
//           // printf("\n");
//           ptr1 = multi;
//           diff = subtraction(La, ptr1);

//           // display_num(diff);
//           // printf("\n");
//           ptr1 = diff;
//           // while (ptr1 != NULL)
//           // {
//           //           printf("%d %d\n", ptr1->data, ptr1->index);
//           //           ptr1 = ptr1->next;
//           // }

//           p = diff;
//           while (p->next != NULL)
//           {
//                     p = p->next;
//           }
//           if (p->data < 0)
//                     i--;
//           else
//           {
//                     comp = compare_lists(diff, Lb);
//                     if (comp == 2)
//                     {
//                               cnt = i;
//                               i = -1;
//                     }
//                     if (comp == 1)
//                     {
//                               i++;
//                               if(i>=pow(10,j)){
//                                         total_cnt=j+1;
//                               }
//                               else{
//                                         j++;
//                               }
//                     }
//           }
//           // L=NULL;
//           diff = NULL;
//           multi = NULL;
//           ptr1 = NULL;
//           // printf("%d\n", i);

//           // La = diff;
//           // p = La;
//           // q = Lb;

//           // while (p->next != NULL)
//           // {
//           //         p = p->next;
//           // }
//           // cnt1 = p->index;
//           // p = La;
//           // if (cnt1 == cnt2)
//           // {
//           //         while (p != NULL)
//           //         {
//           //                 if (p->data < q->data)
//           //                 {
//           //                         cnt1 = cnt1 - 1;
//           //                         p = NULL;
//           //                 }

//           //                 else
//           //                 {
//           //                         p = p->next;
//           //                         q = q->next;
//           //                 }
//           //         }
//           // }

//           // printf("%d %d \n", cnt1, cnt2);
// }
// // printf("%d", cnt);

// return cnt;
// }

node *division(list La, list Lb)
{
          node *p, *q, *r, *s, *t, *u, *v, *z, *L1, *L2, *multi, *diff, *result;
          int i = 9, comp, ind,cnt=0;;
          // comp = compare_lists(La, Lb);
          // if (comp == 2)
          // {
          //            res = (node *)malloc(sizeof(node));

          // }

          L1 = reverse_list(&La);
          // L2 = reverse_list(&Lb);
          p = L1;
          // q = L2;
          list L3, L, L4, res;
          init_list(&L);
          L = (node *)malloc(sizeof(node));
          // L->data = i;
          // L->index = 0;
          // L->next = NULL;

          init_list(&L3);
          init_list(&res);
          // res = (node *)malloc(sizeof(node));
          // u = res;
          // printf("Lb\r");
          // r = Lb;
          // while (r != NULL)
          // {
          //           printf("%d %d\n", r->data, r->index);
          //           r = r->next;
          // }
          // printf("\n");
          // printf("La\n");
          // p = La;
          // while (p != NULL)
          // {
          //           printf("%d %d\n", p->data, p->index);
          //           p = p->next;
          // }
          // printf("\n");

          while (i >= 0)
          {
                    L->data = i;
                    L->index = 0;
                    L->next = NULL;
                    // printf("%d\n", L->data);
                    // printf("%d\n", i);
                    if (i == 9)
                    {
                              // printf("work\n");
                              // node *ptr2 = L3;
                              // // display_num(multi);
                              // while (ptr2 != NULL)
                              // {
                              //           printf("%d %d\n", ptr2->data, ptr2->index);
                              //           ptr2 = ptr2->next;
                              // }
                              s = L3;
                              t = NULL;

                              if (L3 == NULL)
                              {
                                        ind=0;
                                        L3 = (node *)malloc(sizeof(node));
                                        L3->data = p->data;
                                        L3->index = ind;
                                        L3->next = NULL;
                                        ind++;
                                        // node *ptr2 = L3;
                                        // // display_num(multi);
                                        // while (ptr2 != NULL)
                                        // {
                                        //           printf("%d %d\n", ptr2->data, ptr2->index);
                                        //           ptr2 = ptr2->next;
                                        // }
                              }
                              else
                              {
                                        insert_begin(&L3, p->data, 0);
                                        q = L3;
                                        ind = q->index;
                                        ind++;
                                        q = q->next;
                                        while (q != NULL)
                                        {
                                                  q->index = ind;
                                                  ind++;
                                                  q = q->next;
                                        }

                                        // while (s != NULL)
                                        // {
                                        //           t = s;
                                        //           s = s->next;
                                        // }

                                        // t->next = (node *)malloc(sizeof(node));
                                        // ind = t->index;
                                        // t->index = ind + 1;
                                        // t = t->next;
                                        // t->data = p->data;
                                        // t->index = ind;
                                        // t->next = NULL;
                                        // node *ptr2 = L3;
                                        // // display_num(multi);
                                        // while (ptr2 != NULL)
                                        // {
                                        //           printf("%d %d\n", ptr2->data, ptr2->index);
                                        //           ptr2 = ptr2->next;
                                        // }
                              }
                              // printf("L3\n");
                              // q = L3;
                              // while (q != NULL)
                              // {
                              //           printf("%d %d\n", q->data, q->index);
                              //           q = q->next;
                              // }
                              // printf("\n");

                              // L4 = reverse_list(&L3);
                              L4 = L3;
                    }

                    multi = multiplication(Lb, L);
                    // node *ptr2 = multi;
                    // // display_num(multi);
                    // printf("Multi\n");
                    // while (ptr2 != NULL)
                    // {
                    //           printf("%d %d\n", ptr2->data, ptr2->index);
                    //           ptr2 = ptr2->next;
                    // }
                    // printf("\n");
                    // node *ptr4 = L4;
                    // // display_num(multi);
                    // while (ptr4 != NULL)
                    // {
                    //           printf("%d %d\n", ptr4->data, ptr4->index);
                    //           ptr4 = ptr4->next;
                    // }
                    diff = subtraction(L4, multi);
                    // printf("Subtraction\n");
                    // node *ptr1 = diff;
                    // while (ptr1 != NULL)
                    // {
                    //           printf("%d %d\n", ptr1->data, ptr1->index);
                    //           ptr1 = ptr1->next;
                    // }
                    // printf("\n");
                    r = diff;
                    while (r != NULL)
                    {
                              z = r;
                              r = r->next;
                    }
                    if (z->data < 0)
                    {
                              i--;
                              // printf("%d\n", i);
                    }
                    else
                    {
                              cnt++;
                              printf("%d\n",cnt);
                              if (res == NULL)
                              {
                                        res = (node *)malloc(sizeof(node));
                                        res->data = i;
                                        res->index = 0;
                                        res->next = NULL;
                                        // node *ptr3 = res;

                                        // while (ptr3 != NULL)
                                        // {
                                        //           printf("%d %d\n", ptr3->data, ptr3->index);
                                        //           ptr3 = ptr3->next;
                                        // }
                              }
                              else

                              {
                                        u = res;
                                        while (u != NULL)
                                        {
                                                  v = u;
                                                  u = u->next;
                                        }

                                        v->next = (node *)malloc(sizeof(node));
                                        ind = v->index;
                                        ind++;
                                        v = v->next;
                                        v->data = i;
                                        v->index = ind;
                                        ind++;
                                        v->next = NULL;
                                        // node *ptr4 = res;

                                        // while (ptr4 != NULL)
                                        // {
                                        //           printf("%d %d\n", ptr4->data, ptr4->index);
                                        //           ptr4 = ptr4->next;
                                        // }
                              }

                              L3 = NULL;
                              L3 = diff;
                              if (L3->data == 0 && L3->next == NULL)
                                        L3 = NULL;
                              // printf("Diff\n");
                              // node *ptr3 = L3;

                              // while (ptr3 != NULL)
                              // {
                              //           printf("%d %d\n", ptr3->data, ptr3->index);
                              //           ptr3 = ptr3->next;
                              // }
                              if (p->next == NULL)
                              {
                                        // if(L3->data!=0){

                                        // }
                                        i = -1;
                              }
                              else
                              {

                                        i = 9;
                                        // printf("%d\n", i);
                                        p = p->next;
                              }
                    }
          }
          // return res;
          p = res;
          q = res;
          while (p != NULL)
          {
                    if (p->data == 0)
                    {
                              while (q != NULL)
                              {
                                        q->index = q->index - 1;
                                        q = q->next;
                              }
                              q = res;
                              res = p->next;
                              p = p->next;
                    }
                    else{
                              p=NULL;
                    }

                    
          }
          // return res;
          // result = remove_trailing_zeroes(&res);
          if (res == NULL)
          {
                    res = (node *)malloc(sizeof(node));
                    res->data = 0;
                    res->index = 0;
                    res->next = NULL;
                    result = reverse_list(&res);
                    p = result;
                    p->index = 0;
                    ind = 0;
                    p = p->next;
                    while (p != NULL)
                    {

                              p->index = ind + 1;
                              ind = p->index;
                              p = p->next;
                    }
                    res = reverse_list(&result);
                    return res;
          }
          else
          {
                    result = reverse_list(&res);
                    p = result;
                    p->index = 0;
                    ind = 0;
                    ind++;
                    p = p->next;
                    while (p != NULL)
                    {

                              p->index = ind;
                              ind++;
                              p = p->next;
                    }
                    // res = reverse_list(&result);
                    return result;
          }
}

node *power(list La, list Lb)
{
          long long int num;
          int i = 0;
          node *res, *L;
          L = La;
          num = display_num_int(Lb);
          for (i = 0; i < num - 1; i++)
          {
                    res = multiplication(L, La);
                    L = res;
          }
          return res;
}

node *evaluation(char *str, int cnt, int total_cnt, List L)
{
          // display_New_List(L);
          // printf("total cnt %d\n", total_cnt);
          // printf("total cnt %d\n", cnt);
          Node *ptr;
          node *op_arr;
          // list L1;
          // init_list(&L1);
          // stack S1;
          // init_stack(&S1, 1000);
          // char op[50];
          char_list op;
          op = NULL;
          node_char *p, *q, *r, *t, *x;
          node *y;
          int i = 0, j = 0, ind = 0;

          while (i < total_cnt)
          {

                    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                    {
                              // p = op;
                              if (op == NULL)
                              {
                                        op = (node_char *)malloc(sizeof(node_char));
                                        p = op;
                                        p->ch = str[i];
                                        p->index = ind;
                                        ind++;
                                        p->next = NULL;
                                        i++;
                              }
                              else
                              {
                                        p = op;
                                        while (p->next != NULL)
                                        {
                                                  p = p->next;
                                        }
                                        p->next = (node_char *)malloc(sizeof(node_char));
                                        p = p->next;
                                        p->ch = str[i];
                                        // printf("char %c\n",p->ch);
                                        p->index = ind;
                                        ind++;
                                        p->next = NULL;
                                        i++;
                              }
                    }
                    else
                              i++;
          }

          // commented

          // p = op;
          // while (p != NULL)
          // {
          //           printf("%c \n", p->ch);
          //           p = p->next;
          // }
          precedence(op, &op_arr, cnt);
          // node *s;
          // s = op_arr;
          // while (s != NULL)
          // {
          //           printf("%d \n", s->data);
          //           s = s->next;
          // }
          // for (i = 0; i < cnt; i++)
          // {
          //           printf("%c\n", op[i]);
          // }
          // for (i = 0; i < cnt; i++)
          // {
          //           printf("%d\n", op_arr[i]);
          // }

          // int i = 0, ind = 0, k = 0, j = 0;
          // list arr[cnt + 1];
          // int op_arr[cnt];
          // list L1;
          // init_list(&L1);
          // stack S1;
          // init_stack(&S1, 1000);
          // char op[50], sort_arr[50];

          // while (i < total_cnt)
          // {
          //           while (str[i] >= '0' && str[i] <= '9')
          //           {
          //                     push(&S1, str[i] - '0');
          //                     i++;
          //           }
          //           arr[k] = (node *)malloc(sizeof(node));
          //           arr[k]->data = pop(&S1);
          //           arr[k]->index = ind;
          //           ind++;
          //           arr[k]->next = NULL;
          //           node *p;
          //           p = arr[k];
          //           while (!(is_stack_empty(S1)))
          //           {

          //                     p->next = (node *)malloc(sizeof(node));
          //                     p = p->next;
          //                     p->data = pop(&S1);
          //                     p->index = ind;
          //                     ind++;
          //                     p->next = NULL;
          //           }
          //           ind = 0;
          //           op[j] = str[i];
          //           j++;
          //           k++;

          //           i++;
          // }
          // precedence(op, op_arr, cnt);

          // for (i = 0; i < cnt + 1; i++)
          // {
          //         print_nodes(arr[i]);
          // }
          Node *ptr1, *ptr2;
          ptr1 = L;
          ptr2 = L;
          // // int no;
          node *result;

          // ptr1 = division(arr[0], arr[1]);
          // ptr1 = power(arr[0], arr[1]);
          // no = division(arr[0], arr[1]);
          // printf("%d", no);
          // ptr1 = arr[0];
          // ptr2 = arr[1];
          // while (ptr1 != NULL)
          // {
          //           printf("%d %d\n", ptr1->data, ptr1->index);
          //           ptr1 = ptr1->next;
          // }
          // while (ptr2 != NULL)
          // {
          //           printf("%d %d\n", ptr2->data, ptr2->index);
          //           ptr2 = ptr2->next;
          // }

          // display_num(ptr1);
          // int max = 0;
          // for (i = 0; i < cnt; i++)
          // {
          //           if (max < op_arr)
          //                     max = op_arr;
          // }
          // k = 0;
          // while (max >= 0)
          // {
          //           for (i = 0; i < cnt; i++)
          //           {
          //                     if (op_arr[i] == max)
          //                     {
          //                               sort_arr[k] = op[i];
          //                               k++;
          //                     }
          //           }
          //           max--;
          // }

          node *s = op_arr;
          node *z;
          int max = 0, flag = 0, flag1 = 0;
          while (s != NULL)
          {
                    if (max < s->data)
                    {
                              max = s->data;

                              s = s->next;
                    }
                    else
                    {
                              s = s->next;
                    }
          }
          // printf("%d", max);
          ptr = L;
          int search = 0;
          // while (ptr != NULL)
          // {
          while (max >= 0)
          {
                    // printf("maxup=%d\n",max);
                    search = 0;
                    s = op_arr;
                    while (s != NULL)
                    {
                              if (s->data == max)
                              {
                                        search = 1;
                                        s = s->next;
                              }
                              else
                                        s = s->next;
                    }
                    // printf("%d search\n",search);
                    if (search == 1)
                    {

                              // printf("Works\n");
                              flag = 0;
                              flag1 = 0;
                              ptr = L;
                              ptr1 = L;
                              ptr2 = L;
                              // display_New_List(L);
                              // s = op_arr;
                              // while (s != NULL)
                              // {
                              //           printf("op array%d %d\n", s->data, s->index);
                              //           s = s->next;
                              // }
                              s = op_arr;
                              while (s->data != max)
                              {
                                        s = s->next;
                              }
                              i = s->index;
                              // printf("%d\n",i);

                              q = op;
                              // printf("%c %d\n", q->ch, q->index);
                              while (q->index != i)
                              {
                                        q = q->next;
                              }
                              // printf("%c\n", q->ch);
                              switch (q->ch)
                              {
                              case '+':
                                        while (ptr1->index1 != i)
                                        {
                                                  ptr1 = ptr1->right;
                                        }
                                        while (ptr2->index1 != i + 1)
                                        {
                                                  ptr2 = ptr2->right;
                                        }
                                        result = addition(ptr1->down, ptr2->down);
                                        // node *res;
                                        // res = result;
                                        // while (res != NULL)
                                        // {
                                        //           printf("%d %d\n", res->data, res->index);
                                        //           res = res->next;
                                        // }
                                        // result = display_num(ptr1);
                                        ptr1->down = NULL;
                                        ptr2->down = NULL;
                                        ptr1->down = result;
                                        ptr1->right = ptr2->right;
                                        ptr2 = ptr2->right;
                                        ind = ptr1->index1;
                                        while (ptr2 != NULL)
                                        {

                                                  ptr2->index1 = ind + 1;
                                                  ind++;
                                                  ptr2 = ptr2->right;
                                        }

                                        r = op;
                                        t = r;
                                        while (r->ch != q->ch)
                                        {
                                                  t = r;
                                                  r = r->next;
                                        }
                                        // r = r->next;
                                        // t->next = r->next;
                                        ind = t->index;
                                        // printf("Index %d\n", ind);
                                        if (op->ch == q->ch)
                                        {
                                                  op = t->next;
                                                  t->next = NULL;
                                                  t = t->next;
                                        }
                                        else
                                        {
                                                  if (r == NULL)
                                                  {
                                                            t->next = NULL;
                                                  }
                                                  else
                                                            t->next = r->next;
                                                  if (r != NULL)
                                                            r->next = NULL;
                                                  t = t->next;
                                        }
                                        // x = delete_a_charnode(&op, q->ch, i);
                                        // printf("\n");
                                        // r = r->next;
                                        //  r = op;
                                        // while (r != NULL)
                                        // {
                                        //           printf("%c %dnew\n", r->ch, r->index);
                                        //           r = r->next;
                                        // }
                                        // if (t == NULL)
                                        //           r = NULL;
                                        // else
                                        // {

                                        //           while (t != NULL)
                                        //           {

                                        //                     t->index = ind;
                                        //                     printf("tind%d\n", t->index);
                                        //                     ind++;
                                        //                     t = t->next;
                                        //           }
                                        // }
                                        r = op;
                                        ind = 0;
                                        while (r != NULL)
                                        {
                                                  r->index = ind;
                                                  ind++;
                                                  r = r->next;
                                        }
                                        // printf("%d\n", max);
                                        s = op_arr;
                                        z = s;
                                        while (s->data != max)
                                        {
                                                  z = s;
                                                  s = s->next;
                                        }
                                        // s = s->next;
                                        // z->next = s->next;
                                        ind = z->index;
                                        // y = delete_a_node(&op_arr, max, i);
                                        // s = y;
                                        // printf("\n");
                                        if (op_arr->data == max)
                                        {
                                                  op_arr = z->next;
                                                  z->next = NULL;
                                                  z = z->next;
                                        }
                                        else
                                        {
                                                  if (s == NULL)
                                                            z->next = NULL;
                                                  else
                                                            z->next = s->next;
                                                  if (s != NULL)
                                                            s->next = NULL;
                                                  z = z->next;
                                        }
                                        // s = s->next;
                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind=0;
                                                  s=op_arr;

                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }
                                        // display_New_List(L);
                                        // r = op;
                                        // while (r != NULL)
                                        // {
                                        //           printf("%c %d\n", r->ch, r->index);
                                        //           r = r->next;
                                        // }
                                        // s = op_arr;
                                        // while (s != NULL)
                                        // {
                                        //           printf("%d %d\n", s->data, s->index);
                                        //           s = s->next;
                                        // }

                                        // while (ptr1 != NULL)
                                        // {
                                        //           printf("%d %d\n", ptr1->data, ptr1->index);
                                        //           ptr1 = ptr1->next;
                                        // }
                                        // arr[i + 1] = ptr1;
                                        break;

                              case '-':
                                        while (ptr1->index1 != i)
                                        {
                                                  ptr1 = ptr1->right;
                                        }
                                        while (ptr2->index1 != i + 1)
                                        {
                                                  ptr2 = ptr2->right;
                                        }
                                        result = subtraction(ptr1->down, ptr2->down);
                                        // node *res1;
                                        // res1=result;
                                        // while(res!=NULL){
                                        //           printf("%d %d",res1->data,res1->index);
                                        //           res1=res1->next;
                                        // }
                                        // result = display_num(ptr1);
                                        ptr1->down = NULL;
                                        ptr2->down = NULL;
                                        ptr1->down = result;
                                        ptr1->right = ptr2->right;
                                        ptr2 = ptr2->right;
                                        ind = ptr1->index1;
                                        while (ptr2 != NULL)
                                        {

                                                  ptr2->index1 = ind + 1;
                                                  ind++;
                                                  ptr2 = ptr2->right;
                                        }

                                        r = op;
                                        t = r;
                                        while (r->ch != q->ch)
                                        {
                                                  t = r;
                                                  r = r->next;
                                        }
                                        // r = r->next;
                                        // t->next = r->next;
                                        ind = t->index;
                                        if (op->ch == q->ch)
                                        {
                                                  op = t->next;
                                                  t->next = NULL;
                                                  t = t->next;
                                        }
                                        else
                                        {
                                                  if (r == NULL)
                                                  {
                                                            t->next = NULL;
                                                  }
                                                  else
                                                            t->next = r->next;
                                                  if (r != NULL)
                                                            r->next = NULL;
                                                  t = t->next;
                                        }
                                        // x = delete_a_charnode(&op, q->ch, i);
                                        // printf("\n");
                                        // r = r->next;
                                        // if (op != NULL)
                                        // {

                                        //           while (t != NULL)
                                        //           {
                                        //                     t->index = ind;
                                        //                     ind++;
                                        //                     t = t->next;
                                        //           }
                                        // }
                                        r = op;
                                        ind = 0;
                                        while (r != NULL)
                                        {
                                                  r->index = ind;
                                                  ind++;
                                                  r = r->next;
                                        }
                                        s = op_arr;
                                        z = s;
                                        while (s->data != max)
                                        {
                                                  z = s;
                                                  s = s->next;
                                        }
                                        // z->next = s->next;
                                        // s = s->next;
                                        ind = z->index;
                                        // y = delete_a_node(&op_arr, max, i);
                                        // printf("\n");
                                        if (op_arr->data == max)
                                        {
                                                  op_arr = z->next;
                                                  z->next = NULL;
                                                  z = z->next;
                                        }
                                        else
                                        {
                                                  if (s == NULL)
                                                            z->next = NULL;
                                                  else
                                                            z->next = s->next;
                                                  if (s != NULL)
                                                            s->next = NULL;
                                                  z = z->next;
                                        }
                                        // s = s->next;
                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind=0;
                                                  s=op_arr;

                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }
                                        break;
                              case '*':
                                        while (ptr1->index1 != i)
                                        {
                                                  ptr1 = ptr1->right;
                                        }
                                        while (ptr2->index1 != i + 1)
                                        {
                                                  ptr2 = ptr2->right;
                                        }
                                        result = multiplication(ptr1->down, ptr2->down);
                                        // node *res1;
                                        // res1 = result;
                                        // while (res1 != NULL)
                                        // {
                                        //           printf("%d %d\n", res1->data, res1->index);
                                        //           res1 = res1->next;
                                        // }
                                        // result = display_num(ptr1);
                                        ptr1->down = NULL;
                                        ptr2->down = NULL;
                                        ptr1->down = result;
                                        ptr1->right = ptr2->right;
                                        ptr2 = ptr2->right;
                                        ind = ptr1->index1;
                                        while (ptr2 != NULL)
                                        {

                                                  ptr2->index1 = ind + 1;
                                                  ind++;
                                                  ptr2 = ptr2->right;
                                        }
                                        // printf("hi\n");
                                        r = op;
                                        t = r;
                                        while (r->ch != q->ch)
                                        {
                                                  t = r;
                                                  r = r->next;
                                        }
                                        // t->next = r->next;
                                        // r = r->next;
                                        ind = t->index;
                                        if (op->ch == q->ch)
                                        {
                                                  op = t->next;
                                                  t->next = NULL;
                                                  t = t->next;
                                        }

                                        else
                                        {
                                                  if (r == NULL)
                                                  {
                                                            t->next = NULL;
                                                  }
                                                  else
                                                            t->next = r->next;
                                                  if ( r!= NULL)
                                                            r->next = NULL;
                                                  t = t->next;
                                                  // printf("hi\n");
                                        }
                                        // printf("hi\n");
                                        // delete_a_charnode(&op, q->ch, i);
                                        // printf("\n");
                                        // r = r->next;
                                        // if (op != NULL)
                                        // {
                                        //           while (t != NULL)
                                        //           {

                                        //                     t->index = ind;
                                        //                     ind++;
                                        //                     t = t->next;
                                        //           }
                                        // }
                                        r = op;
                                        ind = 0;
                                        while (r != NULL)
                                        {
                                                  r->index = ind;
                                                  ind++;
                                                  r = r->next;
                                        }
                                        // printf("hi\n");
                                        s = op_arr;
                                        z = s;
                                        while (s->data != max)
                                        {
                                                  z = s;
                                                  s = s->next;
                                        }
                                        // s = s->next;
                                        // z->next = s->next;
                                        ind = z->index;
                                        // delete_a_node(&op_arr, max, i);
                                        // printf("\n");
                                        if (op_arr->data == max)
                                        {
                                                  op_arr = z->next;
                                                  z->next = NULL;
                                                  z = z->next;
                                        }
                                        else
                                        {
                                                  if (s == NULL)
                                                            z->next = NULL;
                                                  else
                                                            z->next = s->next;
                                                  if (s != NULL)
                                                            s->next = NULL;
                                                  z = z->next;
                                        }
                                        // printf("hi\n");
                                        // s = s->next;
                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  s=op_arr;
                                                  ind=0;
                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }
                                        // r = op;
                                        // while (r != NULL)
                                        // {
                                        //           printf("%c %d\n", r->ch, r->index);
                                        //           r = r->next;
                                        // }
                                        // s = op_arr;
                                        // while (s != NULL)
                                        // {
                                        //           printf("%d %d\n", s->data, s->index);
                                        //           s = s->next;
                                        // }
                                        // display_New_List(L);
                                        break;
                              case '/':
                                        while (ptr1->index1 != i)
                                        {
                                                  ptr1 = ptr1->right;
                                        }
                                        while (ptr2->index1 != i + 1)
                                        {
                                                  ptr2 = ptr2->right;
                                        }
                                        result = division(ptr1->down, ptr2->down);
                                        // node *res;
                                        // res=result;
                                        // while(res!=NULL){
                                        //           printf("%d %d",res->data,res->index);
                                        //           res=res->next;
                                        // }
                                        // result = display_num(ptr1);
                                        ptr1->down = NULL;
                                        ptr2->down = NULL;
                                        ptr1->down = result;
                                        ptr1->right = ptr2->right;
                                        ptr2 = ptr2->right;
                                        ind = ptr1->index1;
                                        while (ptr2 != NULL)
                                        {

                                                  ptr2->index1 = ind + 1;
                                                  ind++;
                                                  ptr2 = ptr2->right;
                                        }

                                        r = op;
                                        t = r;
                                        while (r->ch != q->ch)
                                        {
                                                  t = r;
                                                  r = r->next;
                                        }
                                        // t->next = r->next;
                                        // r = r->next;
                                        ind = t->index;
                                        if (op->ch == q->ch)
                                        {
                                                  op = t->next;
                                                  t->next = NULL;
                                                  t = t->next;
                                        }
                                        else
                                        {
                                                  if (r == NULL)
                                                  {
                                                            t->next = NULL;
                                                  }
                                                  else
                                                            t->next = r->next;
                                                  if (r != NULL)
                                                            r->next = NULL;
                                                  t = t->next;
                                        }
                                        // delete_a_charnode(&op, q->ch, i);
                                        // printf("\n");
                                        // r = r->next;
                                        // if (op != NULL)
                                        // {
                                        //           while (t != NULL)
                                        //           {

                                        //                     t->index = ind;
                                        //                     ind++;
                                        //                     t = t->next;
                                        //           }
                                        // }
                                        r = op;
                                        ind = 0;
                                        while (r != NULL)
                                        {
                                                  r->index = ind;
                                                  ind++;
                                                  r = r->next;
                                        }
                                        s = op_arr;
                                        z = s;
                                        while (s->data != max)
                                        {
                                                  z = s;
                                                  s = s->next;
                                        }
                                        // z->next = s->next;
                                        // s = s->next;
                                        ind = z->index;
                                        if (op_arr->data == max)
                                        {
                                                  op_arr = z->next;
                                                  z->next = NULL;
                                                  z = z->next;
                                        }
                                        else
                                        {
                                                  if (s == NULL)
                                                            z->next = NULL;
                                                  else
                                                            z->next = s->next;
                                                  if (s != NULL)
                                                            s->next = NULL;
                                                  z = z->next;
                                        }
                                        // delete_a_node(&op_arr, max, i);
                                        // printf("\n");
                                        // s = s->next;
                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind=0;
                                                  s=op_arr;
                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }
                                        break;
                              case '^':
                                        while (ptr1->index1 != i)
                                        {
                                                  ptr1 = ptr1->right;
                                        }
                                        while (ptr2->index1 != i + 1)
                                        {
                                                  ptr2 = ptr2->right;
                                        }
                                        result = power(ptr1->down, ptr2->down);
                                        // node *res;
                                        // res=result;
                                        // while(res!=NULL){
                                        //           printf("%d %d",res->data,res->index);
                                        //           res=res->next;
                                        // }
                                        // result = display_num(ptr1);
                                        // printf("hi1\n");
                                        ptr1->down = NULL;
                                        ptr2->down = NULL;
                                        ptr1->down = result;
                                        ptr1->right = ptr2->right;
                                        ptr2 = ptr2->right;
                                        ind = ptr1->index1;
                                        while (ptr2 != NULL)
                                        {

                                                  ptr2->index1 = ind + 1;
                                                  ind++;
                                                  ptr2 = ptr2->right;
                                        }

                                        r = op;
                                        t = r;
                                        while (r->ch != q->ch)
                                        {
                                                  t = r;
                                                  r = r->next;
                                        }
                                        // t->next = r->next;
                                        // r = r->next;
                                        ind = t->index;
                                        if (op->ch == q->ch)
                                        {
                                                  op = t->next;
                                                  t->next = NULL;
                                                  t = t->next;
                                        }
                                        else
                                        {
                                                  if (r == NULL)
                                                  {
                                                            t->next = NULL;
                                                  }
                                                  else
                                                            t->next = r->next;
                                                  if (r != NULL)
                                                            r->next = NULL;
                                                  t = t->next;
                                        }
                                        // printf("hi2\n");
                                        // delete_a_charnode(&op, q->ch, i);
                                        // printf("\n");
                                        // r = r->next;
                                        // if (op != NULL)
                                        // {
                                        //           while (t != NULL)
                                        //           {

                                        //                     t->index = ind;
                                        //                     ind++;
                                        //                     t = t->next;
                                        //           }
                                        // }
                                        r = op;
                                        ind = 0;
                                        while (r != NULL)
                                        {
                                                  r->index = ind;
                                                  ind++;
                                                  r = r->next;
                                        }
                                        // printf("hi3\n");
                                        s = op_arr;
                                        z = s;
                                        while (s->data != max)
                                        {
                                                  z = s;
                                                  s = s->next;
                                        }
                                        // z->next = s->next;
                                        // s = s->next;
                                        ind = z->index;
                                        if (op_arr->data == max)
                                        {
                                                  op_arr = z->next;
                                                  z->next = NULL;
                                                  z = z->next;
                                        }
                                        else
                                        {
                                                  if (s == NULL)
                                                            z->next = NULL;
                                                  else
                                                            z->next = s->next;
                                                  if (s != NULL)
                                                            s->next = NULL;
                                                  z = z->next;
                                        }
                                        // printf("hi4\n");
                                        // delete_a_node(&op_arr, max, i);
                                        // printf("\n");
                                        // s = s->next;
                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind=0;
                                                  s=op_arr;
                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }
                                        // printf("hi5\n");
                                        break;
                              }
                              // s = op_arr;
                              // z = s;
                              if (op_arr == NULL)
                                        max = -1;
                              else
                              {
                                        s = op_arr;
                                        while (s != NULL)
                                        {
                                                  if (s->data == max)
                                                  {
                                                            flag = 1;
                                                            s = s->next;
                                                  }
                                                  else
                                                  {
                                                            s = s->next;
                                                  }
                                        }
                              }
                              // printf("max=%d\n", max);
                              // printf("flag %d \n", flag);
                              if (flag == 0)
                              {
                                        max--;
                                        // s = op_arr;
                                        // while (s != NULL)
                                        // {
                                        //           if (s->data == max)
                                        //           {
                                        //                     flag1 = 1;
                                        //                     s = s->next;
                                        //           }
                                        //           else
                                        //           {

                                        //                     flag1 = 2;

                                        //                     s = s->next;
                                        //           }
                                        // }
                              }
                              // printf("flag1 %d \n", flag1);
                              // if (flag1 == 2)
                              // {
                              //           max--;
                              // }

                              ptr1 = L;
                              if (ptr1->right == NULL)
                              {
                                        max = -1;
                              }
                    }
                    else
                    {
                              max--;
                    }
          }
          // display_New_List(L);

          return L->down;
}

Node *initt(char *str, int cnt, int total_cnt)
{
          List L;
          L = NULL;
          Node *q;
          // q = L;
          node *p;
          // Node *p;
          // p=L;
          int i = 0, ind = 0, k = 0, j = 0, index_for_newlist = 0;

          // int op_arr[cnt];
          list L1;
          init_list(&L1);
          stack S1;
          init_stack(&S1, 1000);
          // char op[50];
          while (i < total_cnt)
          {
                    if (str[i] >= '0' && str[i] <= '9')
                    {
                              while (str[i] >= '0' && str[i] <= '9')
                              {
                                        push(&S1, str[i] - '0');
                                        i++;
                              }
                              if (L == NULL)
                              {
                                        L = (Node *)malloc(sizeof(Node));
                                        q = L;
                                        L->right = NULL;
                                        L->index1 = index_for_newlist;
                                        index_for_newlist++;
                                        L->down = (node *)malloc(sizeof(node));
                                        p = L->down;
                                        p->data = pop(&S1);
                                        p->index = ind;
                                        ind++;
                                        p->next = NULL;
                                        // printf("%d\n",p->data);
                              }
                              else
                              {
                                        q->right = (Node *)malloc(sizeof(Node));
                                        q = q->right;
                                        q->right = NULL;
                                        q->index1 = index_for_newlist;
                                        index_for_newlist++;
                                        q->down = (node *)malloc(sizeof(node));
                                        p = q->down;
                                        p->data = pop(&S1);
                                        p->index = ind;
                                        ind++;
                                        p->next = NULL;
                              }

                              // node *q;
                              // q=p;
                              while (!(is_stack_empty(S1)))
                              {

                                        p->next = (node *)malloc(sizeof(node));
                                        p = p->next;
                                        p->data = pop(&S1);
                                        p->index = ind;
                                        ind++;
                                        p->next = NULL;
                              }
                    }
                    // if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                    // {
                    //           i++;
                    // }

                    // node *q;
                    // q=p;

                    ind = 0;
                    // op[j] = str[i];
                    // j++;
                    // k++;

                    i++;
                    // q = q->right;
          }
          // precedence(op, op_arr, cnt);
          // display_New_List(L);
          // Node *r;
          // node *s;
          // r = L;
          // while (r != NULL)
          // {
          //           printf("Index1 %d\n", r->index1);
          //           s = r->down;
          //           while (s != NULL)
          //           {
          //                     printf("%d %d\n", s->data, s->index);
          //                     s = s->next;
          //           }
          //           r = r->right;
          // }

          return L;
}

int main()
{
          list L1;
          List L2;
          Node *ptr, *res;
          node *rev;

          char str[100];
          scanf("%s", str);
          int i = 0, count = 0, total_count = 0;
          while (str[i] != '\0')
          {
                    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                    {
                              count++;
                    }
                    total_count++;
                    i++;
          }

          // printf("%d %d",count,total_count);

          ptr = initt(str, count, total_count);
          // Node *ptr4=L2;
          // Node *ptr5=L2;
          // ptr5=ptr5->right;

          // display_New_List(ptr);
          // res = multiplication(ptr4->down,ptr5->down);
          // display_New_List(res);
          // display_num(res);
          rev = evaluation(str, count, total_count, ptr);
          // rev=reverse_list(&res->down);
          display_num(rev);
          // display_New_List(res);
          // node *ptr;
          // ptr = init(str, count, total_count);
          // while (ptr != NULL)
          // {
          //         printf("%d %d\n", ptr->data, ptr->index);
          //         ptr = ptr->next;
          // }

          return 0;
}