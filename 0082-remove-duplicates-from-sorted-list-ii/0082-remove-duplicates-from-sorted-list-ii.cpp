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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !head->next) return head;   //nothing or one node
        ListNode* temp= new ListNode(-1);
        temp->next=head;
        ListNode* curr=head;
        ListNode* prev=temp;
        while(curr )
        {
            if(curr->next && curr->val == curr->next->val)
            {
                int x=curr->val;
               while(curr && curr->val == x)
               {
                    ListNode* toDelete=curr;
                    curr=curr->next;
                    prev->next=curr;
                    delete toDelete; 
               }
            }
            else 
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return temp->next;
        
    }
};