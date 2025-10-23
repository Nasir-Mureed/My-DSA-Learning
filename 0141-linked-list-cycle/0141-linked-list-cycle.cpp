/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(!head)  // empty list
            return false;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast&& fast->next && slow!=fast)  //loops stop when either reached end or cycle found
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!fast || !fast->next)  // if nullptr then no cycle
            return false;
        
        return true;
        
    }
};