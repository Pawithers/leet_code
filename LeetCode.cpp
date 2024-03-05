 #include "LeetCode.h"

 bool LeetCode_Problems::isPalindrome(int x)
 {
        if (x < 0)
        {
            return false;
        }

        int nums[10];

        int mod_num = 10;
        int div_num = 1;
        int sub_num = 0;
        int hold{0};
        int inc = 0;
        bool cont = true;
        while (cont)
        {
            hold = x % mod_num;
            hold -= sub_num;
            hold = hold/div_num;
            nums[inc] = hold;

            div_num = mod_num;
            sub_num += hold;
            mod_num *= 10;
            inc++;
            cont = (x - mod_num/10) >= 0;
        }

        int lim{0};
        if (((inc+1)/2) % 2 != 0)
        {
            lim = (inc)/2;
        }
        else
        {
            lim = (inc+1)/2;
        }

        for (int i = 0; i < lim; i++ )
        {
            if (nums[i] != nums[inc-1-i])
            {
                return false;
            }
        }

        return true;
    }

ListNode* LeetCode_Problems::addTwoNumbers(ListNode* l1, ListNode* l2)
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