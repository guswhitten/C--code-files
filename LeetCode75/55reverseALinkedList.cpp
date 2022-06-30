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
        //If linked list is empty then return head
        if(head==NULL)return head;
        stack<int> s;
        ListNode *temp=head;
        while(temp!=NULL){
            s.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            temp->val=s.top();
            s.pop();
            temp=temp->next;
        }
        return head;
    }
};

/*
Runtime: 6 ms
Memory: 8.5 MB
*/
