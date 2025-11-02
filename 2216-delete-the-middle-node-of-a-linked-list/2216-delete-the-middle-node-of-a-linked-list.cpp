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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(!head || !head->next) return nullptr; // empty or 1 node
       // if(head->next->net)
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast && fast->next) // when ever fast reaches to end slow will be one node behind mid
        {
            slow=slow->next;
            
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
        
    }
};