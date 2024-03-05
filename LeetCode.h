 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class LeetCode_Problems 
{
public:
    bool isPalindrome(int x);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};