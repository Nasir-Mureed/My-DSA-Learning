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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        bool isCollide=false;
        do
        {
            if(!fast || !fast->next)
                return nullptr;  //no cycle
            else
                fast=fast->next->next;
            slow=slow->next;
            
        }
        while(slow != fast);
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast= fast->next;
        }
        return slow;        
    }
};