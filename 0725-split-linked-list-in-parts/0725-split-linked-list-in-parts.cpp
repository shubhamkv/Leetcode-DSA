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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode* temp = head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }

        vector<ListNode*> v(k,NULL);
        int ele = len/k;
        int extra = len%k;
        temp=head;
        int j=0;

        while(temp)
        {
            ListNode* dummy = new ListNode(0);
            ListNode* curr= dummy;
            for(int i=0;i<ele;i++)
            {
                curr->next = new ListNode(temp->val);
                temp = temp->next;
                curr = curr->next;
            }
            if(extra>0)
            {
                curr->next = new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
                extra--;
            }
            v[j] = dummy->next;
            j++;
        }
        return v;
    }
};