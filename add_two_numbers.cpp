#include "add_two_numbers.h"
 
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode ** ans = new ListNode *;
    ListNode ** ans_head = ans;
    int carry_over(0);
    int sum(0);
    while((l1 != nullptr) || (l2 != nullptr))
    {
        *ans = new ListNode;
        (*ans)->val += carry_over;

        if (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val;
        }
        else if (l1 != nullptr)
        {
            sum = l1->val;
        }
        else if (l2 != nullptr)
        {
            sum = l2->val;
        }

        (*ans)->val += sum;

        if ((*ans)->val >= 10)
        {
            carry_over = 1;
            (*ans)->val = (*ans)->val % 10;
        }
        else
        {
            carry_over = 0; 
        }

        if (l1 != nullptr)
        {
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            l2 = l2->next;
        }

        ans = &((*ans)->next);
    }
    if (carry_over > 0)
    {
        *ans = new ListNode;
        (*ans)->val += 1;
    }
    return *ans_head;
}