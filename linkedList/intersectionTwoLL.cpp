/*
Given the heads of two singly linked-lists headA and headB, return the 
node at which the two lists intersect. If the two linked lists have no 
intersection at all, return null.

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*,int> um;        //map to store freq
        
        while (headA || headB) {
            if (um.find(headA) != um.end()) return headA;
            if (um.find(headB) != um.end()) return headB;
            if (headA == headB) return headA;
            if (headA) {
                um[headA]++;
                headA=headA->next;
            }
            if (headB) {
                um[headB]++;
                headB=headB->next;
            }
        }
        return NULL;
    }
};

/*
Runtime: 142 ms
Memory: 21 MB
*/
