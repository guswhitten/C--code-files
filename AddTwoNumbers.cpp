/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0)
    {
        if(!l1 and !l2)
        {
            if(carry > 0)
            {
                return new ListNode(carry);
            }
            return nullptr;
        }
        int op1 = l1 ? l1->val : 0;
        int op2 = l2 ? l2->val : 0;
        int sum = op1 + op2 + carry;
        ListNode* res = new ListNode(sum%10);
        res->next = addTwoNumbers(l1 ? l1->next : nullptr,l2 ? l2->next : nullptr,sum/10);
        return res;
    }
};


/*
Runtime 36 ms
Memory 71.6MB
*/




