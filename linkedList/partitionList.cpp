/*
Given the head of a linked list and a value x, partition it such that all 
nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *fdum = new ListNode(0), *bdum = new ListNode(0),
                 *front = fdum, *back = bdum, *curr = head;
        while (curr) {
            if (curr->val < x) front->next = curr, front = curr;
            else back->next = curr, back = curr;
            curr = curr->next;
        }
        front->next = bdum->next, back->next = nullptr, head = fdum->next;
        delete fdum, bdum;
        return head;
    }
};

/*
Runtime: 4 ms
Memory: 10.4 MB
*/
