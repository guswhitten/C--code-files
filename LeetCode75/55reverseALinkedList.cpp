/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head; //If linked list is empty then return head
        stack<int> s;
        ListNode *temp=head;       //points temp to the same value as head
        while(temp!=NULL){         //iterate thru given linked list
            s.push(temp->val);     //push each int into the stack
            temp=temp->next;       //move to next value
        }                          //while loop closes when temp->NULL
        temp=head;                 //point temp once again to start of head
        while(temp!=NULL){
            temp->val=s.top();     //this time overwrite list values, drawing from the stack
            s.pop();               //pop as you go
            temp=temp->next;       //
        }
        return head;
    }
};

/*
Runtime: 6 ms
Memory: 8.5 MB
*/
