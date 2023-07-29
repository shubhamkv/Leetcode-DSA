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
        
        // Iterative Approach 

        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // ListNode* next;
        
        // while(curr)
        // {
        //     next = curr->next;
        //     curr->next=prev;  // breaking original direction and changing it to new one

        //     prev = curr;
        //     curr = next;

        // }
        // return prev;

        // Recursive Approach -----------------

        if(!head || !head->next)
           return head;
        
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL; 

        return node;

    }
};