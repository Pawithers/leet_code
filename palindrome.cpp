 #include "palindrome.h"

 bool LeetCode_Palindrome::isPalindrome(int x)
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