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

typedef struct float_node
{
          int data;
          int index;
          int deci_index;
          struct float_node *next;
} float_node;
typedef float_node *float_List;

typedef struct node1
{
          int index1;
          int sign;
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
                    printf("%d", res->data);
                    res = res->next;
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

// node *init(char *str, int cnt, int total_cnt)
// {
//           int i = 0, ind = 0, k = 0, j = 0;
//           list arr[cnt + 1];
//           int op_arr[cnt];
//           list L1;
//           init_list(&L1);
//           stack S1;
//           init_stack(&S1, 1000);
//           char op[50];

//           while (i < total_cnt)
//           {
//                     while (str[i] >= '0' && str[i] <= '9')
//                     {
//                               push(&S1, str[i] - '0');
//                               i++;
//                     }
//                     arr[k] = (node *)malloc(sizeof(node));
//                     arr[k]->data = pop(&S1);
//                     arr[k]->index = ind;
//                     ind++;
//                     arr[k]->next = NULL;
//                     node *p;
//                     p = arr[k];
//                     while (!(is_stack_empty(S1)))
//                     {

//                               p->next = (node *)malloc(sizeof(node));
//                               p = p->next;
//                               p->data = pop(&S1);
//                               p->index = ind;
//                               ind++;
//                               p->next = NULL;
//                     }
//                     ind = 0;
//                     op[j] = str[i];
//                     j++;
//                     k++;

//                     i++;
//           }
//           return *arr;
// }

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
}

node *subtraction(list La, list Lb)
{
          struct node *p, *q, *r, **ptr, *res, *result;

          int num1, num2, i = 0, count = 0, diff, borrow = 0, cnt1 = 0, cnt2 = 0, comp;
          // num1 = display_num_int(La);
          // num2 = display_num_int(Lb);
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

node *multiplication(list La, list Lb)
{

          node *p, *q, *r, *res;

          int num, i = 0, k = 0, count = 0, multiply, carry = 0, cnt1 = 0, cnt2 = 0, j = 0, m, ind = 0, zero = 0;

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

node *division(list La, list Lb)
{
          node *p, *q, *r, *s, *t, *u, *v, *z, *L1, *L2, *multi, *diff, *result;
          int i = 9, comp, ind = 0, cnt = 0;

          L1 = reverse_list(&La);
          printf("hi1\n");
          p = L1;

          list L3, L, L4, res;
          init_list(&L);
          L = (node *)malloc(sizeof(node));

          init_list(&L3);
          init_list(&res);

          while (i >= 0)
          {
                    L->data = i;
                    L->index = 0;
                    L->next = NULL;

                    if (i == 9)
                    {

                              s = L3;
                              t = NULL;

                              if (L3 == NULL)
                              {

                                        L3 = (node *)malloc(sizeof(node));
                                        L3->data = p->data;
                                        L3->index = 0;
                                        L3->next = NULL;
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
                                                  q->index = ind + 1;
                                                  ind = q->index;
                                                  q = q->next;
                                        }
                              }

                              L4 = L3;
                    }

                    multi = multiplication(Lb, L);
                    printf("hi2\n");
                    diff = subtraction(L4, multi);
                    printf("hi3\n");
                    r = diff;
                    while (r != NULL)
                    {
                              z = r;
                              r = r->next;
                    }
                    if (z->data < 0)
                    {
                              i--;
                    }
                    else
                    {

                              if (res == NULL)
                              {
                                        res = (node *)malloc(sizeof(node));
                                        res->data = i;
                                        res->index = 0;
                                        res->next = NULL;
                                        printf("hi4\n");
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

                                        v = v->next;
                                        v->data = i;
                                        v->index = ind + 1;

                                        v->next = NULL;
                                        printf("hi5\n");
                              }

                              L3 = NULL;
                              L3 = diff;
                              if (L3->data == 0 && L3->next == NULL)
                                        L3 = NULL;

                              if (p->next == NULL)
                              {

                                        i = -1;
                              }
                              else
                              {

                                        i = 9;

                                        p = p->next;
                              }
                              printf("hi6\n");
                    }
          }

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
                    else
                    {
                              p = p->next;
                    }
          }

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

                    p = p->next;
                    while (p != NULL)
                    {

                              p->index = ind + 1;
                              ind = p->index;
                              p = p->next;
                    }

                    return result;
          }
}
node *modulo(list La, list Lb)
{
          node *p, *q, *r, *s, *t, *u, *v, *z, *L1, *L2, *multi, *diff, *result;
          int i = 9, comp, ind, cnt = 0;

          L1 = reverse_list(&La);

          p = L1;

          list L3, L, L4, res;
          init_list(&L);
          L = (node *)malloc(sizeof(node));

          init_list(&L3);
          init_list(&res);

          while (i >= 0)
          {
                    L->data = i;
                    L->index = 0;
                    L->next = NULL;

                    if (i == 9)
                    {

                              s = L3;
                              t = NULL;

                              if (L3 == NULL)
                              {
                                        ind = 0;
                                        L3 = (node *)malloc(sizeof(node));
                                        L3->data = p->data;
                                        L3->index = ind;
                                        L3->next = NULL;
                                        ind++;
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
                              }

                              L4 = L3;
                    }

                    multi = multiplication(Lb, L);

                    diff = subtraction(L4, multi);

                    r = diff;
                    while (r != NULL)
                    {
                              z = r;
                              r = r->next;
                    }
                    if (z->data < 0)
                    {
                              i--;
                    }
                    else
                    {

                              if (res == NULL)
                              {
                                        res = (node *)malloc(sizeof(node));
                                        res->data = i;
                                        res->index = 0;
                                        res->next = NULL;
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
                              }

                              L3 = NULL;
                              L3 = diff;

                              if (p->next == NULL)
                              {

                                        i = -1;
                                        return L3;
                              }
                              else
                              {
                                        if (L3->data == 0 && L3->next == NULL)
                                                  L3 = NULL;

                                        i = 9;

                                        p = p->next;
                              }
                    }
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

          Node *ptr;
          ptr = L;
          node *op_arr, *y, *a, *b, *res;

          char_list op;
          op = NULL;
          node_char *p, *q, *r, *t, *x;

          int i = 0, j = 0, ind = 0, k = 0;
          // sign[cnt-1];

          while (i < total_cnt)
          {

                    if (str[i] == '(')
                    {

                              i++;

                              if (str[i] == '-')
                              {

                                        i++;
                                        cnt--;

                                        ptr->sign = 1;
                                        ptr = ptr->right;
                              }
                    }
                    if (str[i] == ')')
                    {
                              i++;
                    }

                    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                    {

                              if (op == NULL)
                              {
                                        op = (node_char *)malloc(sizeof(node_char));
                                        p = op;
                                        p->ch = str[i];
                                        p->index = ind;
                                        ind++;
                                        p->next = NULL;
                                        i++;
                                        if (str[i] != '(')
                                        {
                                                  ptr->sign = 0;
                                                  ptr = ptr->right;
                                        }
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
                                        if (str[i] != '(')
                                        {
                                                  ptr->sign = 0;
                                                  ptr = ptr->right;
                                        }
                              }
                    }
                    else
                              i++;
          }

          precedence(op, &op_arr, cnt);

          Node *ptr1, *ptr2;
          ptr1 = L;
          ptr2 = L;

          node *result;

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

          ptr = L;
          int search = 0;

          while (max >= 0)
          {

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

                    if (search == 1)
                    {

                              flag = 0;
                              flag1 = 0;
                              ptr = L;
                              ptr1 = L;
                              ptr2 = L;

                              s = op_arr;
                              while (s->data != max)
                              {
                                        s = s->next;
                              }
                              i = s->index;

                              q = op;

                              while (q->index != i)
                              {
                                        q = q->next;
                              }

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
                                        if (ptr1->sign == 1 && ptr2->sign == 1)
                                        {
                                                  result = addition(ptr1->down, ptr2->down);
                                                  res = result;
                                                  while (res->next != NULL)
                                                  {
                                                            res = res->next;
                                                  }
                                                  res->data = -(res->data);
                                        }
                                        // else if(ptr1->sign==1 && ptr2->sign!=1){
                                        //           result=subtraction(ptr1->down,ptr2->down);
                                        // }
                                        // else if(ptr1->sign!=1 && ptr2->sign==1){
                                        //           result=subtraction(ptr1->down,ptr2->down);
                                        // }
                                        else
                                        {
                                                  if (ptr1->sign == 1)
                                                  {
                                                            a = ptr1->down;
                                                            while (a->next != NULL)
                                                            {
                                                                      a = a->next;
                                                            }
                                                            a->data = -(a->data);
                                                  }
                                                  if (ptr2->sign == 1)
                                                  {
                                                            b = ptr2->down;
                                                            while (b->next != NULL)
                                                            {
                                                                      b = b->next;
                                                            }
                                                            b->data = -(b->data);
                                                  }
                                                  result = addition(ptr1->down, ptr2->down);
                                        }

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

                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind = 0;
                                                  s = op_arr;

                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }

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
                                        if (ptr1->sign == 1)
                                        {
                                                  a = ptr1->down;
                                                  while (a->next != NULL)
                                                  {
                                                            a = a->next;
                                                  }
                                                  a->data = -(a->data);
                                        }
                                        if (ptr2->sign == 1)
                                        {
                                                  b = ptr2->down;
                                                  while (b->next != NULL)
                                                  {
                                                            b = b->next;
                                                  }
                                                  b->data = -(b->data);
                                        }
                                        result = subtraction(ptr1->down, ptr2->down);

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

                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind = 0;
                                                  s = op_arr;

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
                                        if (ptr1->sign == 1)
                                        {
                                                  a = ptr1->down;
                                                  while (a->next != NULL)
                                                  {
                                                            a = a->next;
                                                  }
                                                  a->data = -(a->data);
                                        }
                                        if (ptr2->sign == 1)
                                        {
                                                  b = ptr2->down;
                                                  while (b->next != NULL)
                                                  {
                                                            b = b->next;
                                                  }
                                                  b->data = -(b->data);
                                        }
                                        result = multiplication(ptr1->down, ptr2->down);

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

                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  s = op_arr;
                                                  ind = 0;
                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }

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
                                        if (ptr1->sign == 1)
                                        {
                                                  a = ptr1->down;
                                                  while (a->next != NULL)
                                                  {
                                                            a = a->next;
                                                  }
                                                  a->data = -(a->data);
                                        }
                                        if (ptr2->sign == 1)
                                        {
                                                  b = ptr2->down;
                                                  while (b->next != NULL)
                                                  {
                                                            b = b->next;
                                                  }
                                                  b->data = -(b->data);
                                        }
                                        result = division(ptr1->down, ptr2->down);

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

                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {

                                                  s = op_arr;
                                                  ind = 0;
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
                                        if (ptr1->sign == 1)
                                        {
                                                  a = ptr1->down;
                                                  while (a->next != NULL)
                                                  {
                                                            a = a->next;
                                                  }
                                                  a->data = -(a->data);
                                        }
                                        if (ptr2->sign == 1)
                                        {
                                                  b = ptr2->down;
                                                  while (b->next != NULL)
                                                  {
                                                            b = b->next;
                                                  }
                                                  b->data = -(b->data);
                                        }
                                        result = power(ptr1->down, ptr2->down);
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

                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind = 0;
                                                  s = op_arr;
                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }

                                        break;
                              case '%':
                                        while (ptr1->index1 != i)
                                        {
                                                  ptr1 = ptr1->right;
                                        }
                                        while (ptr2->index1 != i + 1)
                                        {
                                                  ptr2 = ptr2->right;
                                        }
                                        result = modulo(ptr1->down, ptr2->down);
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

                                        if (op_arr == NULL)
                                                  max = -1;
                                        else
                                        {
                                                  ind = 0;
                                                  s = op_arr;
                                                  while (s != NULL)
                                                  {

                                                            s->index = ind;
                                                            ind++;
                                                            s = s->next;
                                                  }
                                        }

                                        break;
                              }

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

                              if (flag == 0)
                              {
                                        max--;
                              }

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

          return L->down;
}

Node *init(char *str, int cnt, int total_cnt)
{
          List L;
          L = NULL;
          Node *q;

          node *p;

          int i = 0, ind = 0, k = 0, j = 0, index_for_newlist = 0, sign = 0, num;

          list L1;

          init_list(&L1);
          stack S1;
          init_stack(&S1, 1000);

          while (i < total_cnt)
          {
                    // if (str[i] == '-' || str[i]=='(')
                    // {
                    //           if (i == 0)
                    //           {
                    //                     sign = 1;
                    //                     i++;
                    //           }
                    //           if(str[i+1]=='-'){
                    //                     sign=1;
                    //                     i++;
                    //           }
                    // }
                    if (str[i] >= '0' && str[i] <= '9')
                    {
                              while (str[i] >= '0' && str[i] <= '9')
                              {
                                        // if (sign == 0)
                                        // {

                                        push(&S1, str[i] - '0');

                                        i++;
                                        // }
                                        // else{
                                        //           num=str[i] -'0';
                                        //           num=-(num);
                                        //           printf("%d",num);
                                        //           push(&S1,num);
                                        //           i++;
                                        //           sign=0;
                                        // }
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

                    ind = 0;

                    i++;
          }
          // printf("ho\n");

          return L;
}
int find_error(char *str, int total_cnt)
{
          int i = 0, brac_cnt1 = 0,brac_cnt2=0;
          while (i < total_cnt)
          {
                    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                    {
                              if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%' || str[i + 1] == '^' || str[i + 1] == ' ')
                              {

                                        // err = 1;
                                        // i++;
                                        return 1;
                              }
                              else
                              {
                                        i++;
                              }
                    }
                    else if (str[i] >= '0' && str[i] <= '9')
                    {
                              i++;
                    }
                    else if (str[i] == '(')
                    {
                              brac_cnt1++;
                              i++;
                    }
                    else if (str[i] == ')')
                    {
                              brac_cnt2++;
                              i++;
                    }
                    else
                    {
                              return 1;
                    }
          }
          if (brac_cnt1==brac_cnt2)
                    return 0;
          else return 1;
}

int main()
{
          list L1;
          List L2;
          Node *ptr, *res;
          node *rev;
          int decimal = 0, i = 0, count = 0, total_count = 0, error = 0;
          char ch = 'a';
          char str[100];
          // while (str[i] != 'q')
          // {

          scanf("%s", str);
          // if (str[i] == 'q')
          //           return 0;
          // switch (ch)
          // {
          // case 'q':
          //           break;
          // default:

          while (str[i] != '\0')
          {
                    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                    {
                              count++;
                    }
                    total_count++;
                    i++;
          }
          // printf("%d %d\n", count, total_count);
          error = find_error(str, total_count);
          if (error == 1)
          {
                    printf("Invalid Input");
          }
          else
          {
                    ptr = init(str, count, total_count);

                    rev = evaluation(str, count, total_count, ptr);

                    display_num(rev);
                    printf("\n");
                    printf("\n");
          }

          // }

          return 0;
}