/*
Given the head of a sorted linked list, delete all duplicates such that each element appears 
only once. Return the linked list sorted as well.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;                               //declare cur to maintain 'head' pointer
        while(cur) {                                        //simply walk thru the LL
        	while(cur->next && cur->val == cur->next->val) {
                //if next node is non-NULL, && next value is duplicate
        		cur->next = cur->next->next;
        	}
        	cur = cur->next;                                //simply walk thru the LL
        }
        return head;
    }
};


/*
Runtime: 31 ms
Memory: 11.5 MB
*/
