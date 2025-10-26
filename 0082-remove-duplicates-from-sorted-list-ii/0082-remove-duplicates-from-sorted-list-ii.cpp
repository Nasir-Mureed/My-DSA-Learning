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
       
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr )
        {
            if(curr==head )
            {
                if(!head || !head->next) return head;   //nothing or one node
                int x=head->next->val;
                if(x==head->val)
                    while(head && head->val == x)
                    {
                        ListNode* toDelete=head;
                        head=head->next;
                        curr=curr->next;
                        delete toDelete; 
                    }
                else
                {
                    prev=curr;
                    curr=curr->next;
                }
            }
            else if(curr->next && curr->val == curr->next->val)
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
        return head;
        
    }
};