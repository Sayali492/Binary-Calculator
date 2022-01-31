#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

typedef struct node
{
        int data;
        int index;
        struct node *next;
} node;
typedef struct node *list;

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
                { //alert:write p->next!=null and not p!=NULL
                        p = p->next;
                }
                p->next = (struct node *)malloc(sizeof(struct node));
                p->next->data = d;
                p->next->next = NULL;
        }
}

void insert_begin(list *L, int d, int place)
{ //here first I had done struct node *L,but it didnt give any op,coz I passed its value.Pass the arguments by reference and then u get the op.
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
void delete_a_node(struct node **L, int d, int pos)
{
        struct node *p, *q;
        int count;
        p = *L;
        q = NULL;
        if (p == NULL)
        {
                return;
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
                        return;
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
                        return;
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
                        return;
                }
        }
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
//stack using array
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

void precedence(char *string, int *array, int count_no)
{
        int i = 0;
        for (i = 0; i < count_no; i++)
        {
                switch (string[i])
                {
                case '+':
                case '-':
                        array[i] = 1;
                        break;
                case '*':
                case '/':
                case '%':
                        array[i] = 2;
                        break;
                }
        }
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
        int i= 0;
        res=reverse_list(&L);
        while(res!=NULL){
                printf("%d",res->data);
                res=res->next;
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
        struct node *p, *q, *r, **ptr, *res;

        int num1, num2, i = 0, count = 0, diff, borrow = 0, cnt1 = 0, cnt2 = 0;
        num1 = display_num_int(La);
        num2 = display_num_int(Lb);
        list P3;
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
                return P3;
        }
        else
        {
                res = remove_trailing_zeroes(&P3);
                r = res;
                if ((cnt2 > cnt1) || (num2 > num1))
                {
                        while (r->next != NULL)
                        {
                                r = r->next;
                        }
                        r->data = (-r->data);
                }
                r = res;
                return res;
        }
}

node *multiplication(node *La, node *Lb)
{

        node *p, *q, *r, *res;

        int num, i = 0, k = 0, count = 0, multiply, carry = 0, cnt1 = 0, cnt2 = 0, j = 0, m, ind = 0;

        list P3;

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
                                        r->data = multiply;
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
        if (min == 0)
        {
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
}

int evaluation(char *str, int cnt, int total_cnt)
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
        precedence(op, op_arr, cnt);

        // for (i = 0; i < cnt + 1; i++)
        // {
        //         print_nodes(arr[i]);
        // }
        node *ptr1;
        // int result;
        ptr1 = multiplication(arr[0], arr[1]);

        // while (ptr1 != NULL)
        // {
        //         printf("%d %d\n", ptr1->data, ptr1->index);
        //         ptr1 = ptr1->next;
                
        // }
        
       display_num(ptr1);
        // int max = 0;
        // for (i = 0; i < cnt; i++)
        // {
        //         if (max < op_arr[i])
        //                 max = op_arr[i];
        // }

        // while (max != 0)
        // {
        //         for (i = 0; i < cnt; i++)
        //         {
        //                 if (op_arr[i] == max)
        //                 {
        //                         switch (op[i])
        //                         {
        //                         case '+':
        //                                 ptr1 = addition(arr[i], arr[i + 1]);
        //                                 result = display_num(ptr1);
        //                                 arr[i] = ptr1;

        //                                 while (ptr1 != NULL)
        //                                 {
        //                                         printf("%d %d\n", ptr1->data, ptr1->index);
        //                                         ptr1 = ptr1->next;
        //                                 }
        //                                 arr[i + 1] = ptr1;
        //                                 break;
        //                         case '-':
        //                                 ptr1 = subtraction(arr[i], arr[i + 1]);
        //                                 result = display_num(ptr1);
        //                                 arr[i] = ptr1;

        //                                 while (ptr1 != NULL)
        //                                 {
        //                                         printf("%d %d\n", ptr1->data, ptr1->index);
        //                                         ptr1 = ptr1->next;
        //                                 }
        //                                 arr[i + 1] = ptr1;
        //                                 break;
        //                         }
        //                 }
        //         }
        //         max--;
        //         return result;
        // }
}

int main()
{
        list L1;
        char str[100];
        scanf("%s", str);
        int i = 0, count = 0, total_count = 0;
        while (str[i] != '\0')
        {
                if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
                {
                        count++;
                }
                total_count++;
                i++;
        }
        // printf("%d %d",count,total_count);
        evaluation(str, count, total_count);

        return 0;
}