/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by 
splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //strategy (iterative):
        //maintain head pointer (will have to return later)
        //declare tail pointer (will change every iteration)
        //ensure both lists are non-empty
        //assign tail pointer to head pointer of list with SMALLEST value
        //while (lists are non NULL)
        //  if (list1 < list2): merge list1 node
        //  otherwise: merge list2 node
        //when a list hits NULL, while loop will end, so
        //add the rest of the other list to the end of the merged list
        //return head pointer
        
        ListNode* mergedHead = list1;    //pointer at head
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1-> val > list2->val) { // ensure head pointer points to lowest value
            mergedHead = list2; 
            list2=list2->next;
        }
        else {list1=list1->next;}
        ListNode* merged = mergedHead;   //pointer at tail
        while (list1 && list2) {        //iterate thru both lists
            if (list1->val < list2->val) {
                merged->next = list1;
                list1=list1->next;
            }
            else {
                merged->next = list2;
                list2=list2->next;
            }
            merged=merged->next;
        }
        if (!list1) merged->next = list2;
        else merged->next=list1;
        return mergedHead;
    }
};

/*
Runtime: 16 ms
Memory: 14.9 MB
*/
